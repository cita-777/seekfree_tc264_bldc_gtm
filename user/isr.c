/*********************************************************************************************************************
* TC264 Opensourec Library ����TC264 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ��� TC264 ��Դ���һ����
*
* TC264 ��Դ�� ��������
* �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
* �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          isr
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          ADS v1.8.0
* ����ƽ̨          TC264D
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����                ��ע
* 2022-09-15       pudding            first version
********************************************************************************************************************/
#include "gtm_pwm.h"
#include "adc.h"
#include "motor.h"
#include "gpio.h"
#include "pwm_input.h"
#include "bldc_config.h"
#include "isr_config.h"
#include "isr.h"

// **************************** PIT�жϺ��� ****************************
IFX_INTERRUPT(cc60_pit_ch0_isr, 0, CCU6_0_CH0_ISR_PRIORITY)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    pit_clear_flag(CCU60_CH0);


}


IFX_INTERRUPT(cc60_pit_ch1_isr, 0, CCU6_0_CH1_ISR_PRIORITY)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    pit_clear_flag(CCU60_CH1);




}

IFX_INTERRUPT(cc61_pit_ch0_isr, 0, CCU6_1_CH0_ISR_PRIORITY)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    pit_clear_flag(CCU61_CH0);




}

IFX_INTERRUPT(cc61_pit_ch1_isr, 0, CCU6_1_CH1_ISR_PRIORITY)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    pit_clear_flag(CCU61_CH1);

    adc_read();

    battery_check();

    bldc_key_scan();     //����ɨ��

    motor_set_dir();

    motor_speed_out();

    phase_change_time_check();

    if(motor_control.run_model)
    {
        spe_g.speed.duty = adc_information.current_board * PWM_PRIOD_LOAD / 4096;
    }
    else
    {
        spe_g.speed.duty = pwm_in_duty;
    }

    motor_check();

    speed_ctrl(spe_g.speed);
}
// **************************** PIT�жϺ��� ****************************

int8 new_data_filter = 0;
IFX_INTERRUPT(gtm_pwm_in, 0, GTM_PWM_IN_PRIORITY)
{
    IfxGtm_Tim_In_update(&driver);

    if(FALSE == driver.newData)
    {
        if(gpio_get_level(MOTOR_PWM_IN_PIN))
        {
            if(new_data_filter > 0)
            {
                new_data_filter --;
            }
            else
            {
                driver.periodTick       = 20000;
                driver.pulseLengthTick  = driver.periodTick;
            }
        }
        else
        {
            new_data_filter = 3;
            driver.periodTick = 20000;
            driver.pulseLengthTick = 0;
        }
    }
    else
    {
        new_data_filter = 0;
    }

    pwm_in_duty = (uint16)func_limit_ab((driver.pulseLengthTick * PWM_PRIOD_LOAD / driver.periodTick), 0, PWM_PRIOD_LOAD);

    if(gpio_get_level(EN_PIN))
    {
        pwm_in_duty = 0;
    }
}

IFX_INTERRUPT (spe_isr, 0, SRC_SPE_INT_PRIO)
{
    pattern_chk();
    if (GTM_SPE0_IRQ_NOTIFY.B.SPE_RCMP)         // ��ת����ƥ���ж�
    {
        GTM_SPE0_IRQ_NOTIFY.B.SPE_RCMP = 1;     // д��1����Ĵ�������

        GTM_SPE0_CMP.B.CMP = (GTM_SPE0_CMP.B.CMP + REV_CNT_VAL) & 0xFFFFFF;     // �ٴ��ۼ���ֵ
        spe_g.irqcnt.spe_rcmp++ ;
    }

    if (GTM_SPE0_IRQ_NOTIFY.B.SPE_DCHG)         // �����ת����仯
    {
        GTM_SPE0_IRQ_NOTIFY.B.SPE_DCHG = 1;
        spe_g.irqcnt.spe_dchg++;
        motor_dir_out();                        // �����ȷ����ת����
    }

    if (GTM_SPE0_IRQ_NOTIFY.B.SPE_PERR)         // ����������Ч
    {
        GTM_SPE0_IRQ_NOTIFY.B.SPE_PERR = 1;
        spe_g.irqcnt.spe_perr++;
        spe0_pattern_cfg();                     // ��������SPEģ��
    }

    if (GTM_SPE0_IRQ_NOTIFY.B.SPE_BIS)          // ��⵽�����źŷ���  ��Ծ�ź� һ���жϳ��ֶ�λ���ֵ�ı�
    {
        GTM_SPE0_IRQ_NOTIFY.B.SPE_BIS = 1;
        spe_g.irqcnt.spe_bis++;
    }

    if (GTM_SPE0_IRQ_NOTIFY.B.SPE_NIPD)         // �µ�����ȷ������ģʽ�����ࣩ
    {
        GTM_SPE0_IRQ_NOTIFY.B.SPE_NIPD = 1;
        spe_g.irqcnt.spe_nipd++;
        spe_g.hall_last = spe_g.hall_now;
        spe_g.hall_now  = GTM_SPE0_CTRL_STAT.B.NIP;     // ��ȡ����ֵ
        phase_change_manage();                          // ���ദ��  �����ٶ�
    }
}

// **************************** �ⲿ�жϺ��� ****************************
IFX_INTERRUPT(exti_ch0_ch4_isr, 0, EXTI_CH0_CH4_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    if(exti_flag_get(ERU_CH0_REQ0_P15_4))           // ͨ��0�ж�
    {
        exti_flag_clear(ERU_CH0_REQ0_P15_4);

    }

    if(exti_flag_get(ERU_CH4_REQ13_P15_5))          // ͨ��4�ж�
    {
        exti_flag_clear(ERU_CH4_REQ13_P15_5);




    }
}

IFX_INTERRUPT(exti_ch1_ch5_isr, 0, EXTI_CH1_CH5_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    if(exti_flag_get(ERU_CH1_REQ10_P14_3))          // ͨ��1�ж�
    {
        exti_flag_clear(ERU_CH1_REQ10_P14_3);



    }

    if(exti_flag_get(ERU_CH5_REQ1_P15_8))           // ͨ��5�ж�
    {
        exti_flag_clear(ERU_CH5_REQ1_P15_8);


    }
}

// ��������ͷpclk����Ĭ��ռ���� 2ͨ�������ڴ���DMA��������ﲻ�ٶ����жϺ���
// IFX_INTERRUPT(exti_ch2_ch6_isr, 0, EXTI_CH2_CH6_INT_PRIO)
// {
//  interrupt_global_enable(0);                     // �����ж�Ƕ��
//  if(exti_flag_get(ERU_CH2_REQ7_P00_4))           // ͨ��2�ж�
//  {
//      exti_flag_clear(ERU_CH2_REQ7_P00_4);
//  }
//  if(exti_flag_get(ERU_CH6_REQ9_P20_0))           // ͨ��6�ж�
//  {
//      exti_flag_clear(ERU_CH6_REQ9_P20_0);
//  }
// }

IFX_INTERRUPT(exti_ch3_ch7_isr, 0, EXTI_CH3_CH7_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    if(exti_flag_get(ERU_CH3_REQ6_P02_0))           // ͨ��3�ж�
    {
        exti_flag_clear(ERU_CH3_REQ6_P02_0);
        camera_vsync_handler();                     // ����ͷ�����ɼ�ͳһ�ص�����
    }
    if(exti_flag_get(ERU_CH7_REQ16_P15_1))          // ͨ��7�ж�
    {
        exti_flag_clear(ERU_CH7_REQ16_P15_1);




    }
}
// **************************** �ⲿ�жϺ��� ****************************


// **************************** DMA�жϺ��� ****************************
IFX_INTERRUPT(dma_ch5_isr, 0, DMA_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    camera_dma_handler();                           // ����ͷ�ɼ����ͳһ�ص�����
}
// **************************** DMA�жϺ��� ****************************


// **************************** �����жϺ��� ****************************
IFX_INTERRUPT(uart0_tx_isr, 0, UART0_TX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart0_handle);


}


IFX_INTERRUPT(uart0_rx_isr, 0, UART0_RX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart0_handle);

#if DEBUG_UART_USE_INTERRUPT                        // ������� debug �����ж�
        debug_interrupr_handler();                  // ���� debug ���ڽ��մ����� ���ݻᱻ debug ���λ�������ȡ
#endif                                              // ����޸��� DEBUG_UART_INDEX ����δ�����Ҫ�ŵ���Ӧ�Ĵ����ж�ȥ

}
IFX_INTERRUPT(uart0_er_isr, 0, UART0_ER_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrError(&uart0_handle);



}

// ����1Ĭ�����ӵ�����ͷ���ô���
IFX_INTERRUPT(uart1_tx_isr, 0, UART1_TX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart1_handle);




}
IFX_INTERRUPT(uart1_rx_isr, 0, UART1_RX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart1_handle);
    camera_uart_handler();                          // ����ͷ��������ͳһ�ص�����
}
IFX_INTERRUPT(uart1_er_isr, 0, UART1_ER_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrError(&uart1_handle);




}


// ����2Ĭ�����ӵ�����ת����ģ��
IFX_INTERRUPT(uart2_tx_isr, 0, UART2_TX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart2_handle);





}
IFX_INTERRUPT(uart2_rx_isr, 0, UART2_RX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart2_handle);
    wireless_module_uart_handler();                 // ����ģ��ͳһ�ص�����

}
IFX_INTERRUPT(uart2_er_isr, 0, UART2_ER_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrError(&uart2_handle);

}



IFX_INTERRUPT(uart3_tx_isr, 0, UART3_TX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrTransmit(&uart3_handle);




}
IFX_INTERRUPT(uart3_rx_isr, 0, UART3_RX_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrReceive(&uart3_handle);

    gps_uart_callback();                            // GPS ���ڻص�����



}
IFX_INTERRUPT(uart3_er_isr, 0, UART3_ER_INT_PRIO)
{
    interrupt_global_enable(0);                     // �����ж�Ƕ��
    IfxAsclin_Asc_isrError(&uart3_handle);





}
// **************************** �����жϺ��� ****************************
