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
* �ļ�����          motor
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          ADS v1.8.0
* ����ƽ̨          TC264D
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����                ��ע
* 2023-02-01       pudding             first version
********************************************************************************************************************/

#include "IFXGTM_TIM_IN.h"
#include "ifxGtm_Tim.h"
#include "zf_common_function.h"
#include "zf_driver_delay.h"
#include "zf_driver_timer.h"
#include "bldc_config.h"
#include "move_filter.h"
#include "pwm_input.h"
#include "gpio.h"
#include "adc.h"
#include "motor.h"

motor_struct motor_control;

uint32 commutation_time_save = 0;                   // ����ʱ��

//-------------------------------------------------------------------------------------------------------------------
// �������     ���ת����Ϣ������ų�ʼ��
// ����˵��     void
// ʹ��ʾ��     motor_information_out_init();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_information_out_init(void)
{
    pwm_init(MOTOR_SPEED_OUT_PIN, 50 , 0);                  // ��ʼ������ٶ�������ţ����ΪƵ�ʱ仯���źţ�������ת��Ϊÿ����5000ת���������ϵ�Ƶ��Ϊ5000Hz��
    gpio_init(MOTOR_DIR_OUT_PIN , GPO, 0, GPO_PUSH_PULL);   // ��ʼ���������������ţ��û��˽��գ�
}

//-------------------------------------------------------------------------------------------------------------------
// �������     �л������
// ����˵��     void
// ʹ��ʾ��     advance_switch();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void advance_switch(void)
{
    GTM_SPE0_CTRL_STAT.B.SPE_EN   = FALSE;

    if(motor_control.set_dir == FORWARD)
    {
        GTM_SPE0_OUT_PAT0.U = MOTOR_FOREWARD_0;     // ��ת�����
        GTM_SPE0_OUT_PAT1.U = MOTOR_FOREWARD_1;
        GTM_SPE0_OUT_PAT2.U = MOTOR_FOREWARD_2;
        GTM_SPE0_OUT_PAT3.U = MOTOR_FOREWARD_3;
        GTM_SPE0_OUT_PAT4.U = MOTOR_FOREWARD_4;
        GTM_SPE0_OUT_PAT5.U = MOTOR_FOREWARD_5;
    }
    else
    {
        GTM_SPE0_OUT_PAT0.U = MOTOR_REVERSAL_0;     // ��ת�����
        GTM_SPE0_OUT_PAT1.U = MOTOR_REVERSAL_1;
        GTM_SPE0_OUT_PAT2.U = MOTOR_REVERSAL_2;
        GTM_SPE0_OUT_PAT3.U = MOTOR_REVERSAL_3;
        GTM_SPE0_OUT_PAT4.U = MOTOR_REVERSAL_4;
        GTM_SPE0_OUT_PAT5.U = MOTOR_REVERSAL_5;
    }
    if(motor_control.brake_flag == 1)
    {
        GTM_SPE0_OUT_PAT0.U = MOTOR_BRAKE;          // ɲ��
        GTM_SPE0_OUT_PAT1.U = MOTOR_BRAKE;
        GTM_SPE0_OUT_PAT2.U = MOTOR_BRAKE;
        GTM_SPE0_OUT_PAT3.U = MOTOR_BRAKE;
        GTM_SPE0_OUT_PAT4.U = MOTOR_BRAKE;
        GTM_SPE0_OUT_PAT5.U = MOTOR_BRAKE;
    }
    GTM_SPE0_CTRL_STAT.B.SPE_EN   = TRUE;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ������ת����
// ����˵��     void
// ʹ��ʾ��     motor_set_dir();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_set_dir(void)
{
    if(gpio_get_level(MOTOR_DIR_IN_PIN) != motor_control.set_dir)
    {
        motor_control.set_dir = gpio_get_level(MOTOR_DIR_IN_PIN);
        advance_switch();
    }
    motor_dir_out();
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ���ռ�ձ����
// ����˵��     void
// ʹ��ʾ��     speed_ctrl();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void speed_ctrl(speed_st speed)
{
    // ռ�ձȲ��ܴ�������ֵ
    if( speed.duty <= speed.period )
    {
        GTM_TOM0_CH0_SR1.U = speed.duty     & 0xFFFF;
        GTM_TOM0_CH0_SR0.U = speed.period   & 0xFFFF;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ���㵱ǰ���ٶ�
// ����˵��     void
// ʹ��ʾ��     calc_speed();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
inline void calc_speed(void)
{
    //ת�ټ���
    int32 speed;

    // ���ת�ټ���˵��
    // 2.commutation_time_save��ͳ�Ƶ�����λ���ʹ���˶���ʱ��
    // 3.ͨ�����ת�����Ƕ���RPM��ʾ��RPM��ʾÿ���ӵ����ת��
    // 3.���תһȦ��Ҫ����Ĵ������� ���������*6
    // 4.��˵��ת�ٵ��� ģ��ʱ��/���λ���ʱ��/(��������� * 6) * 60���������Եõ����ÿ���ӵ�ת��

    speed = FCY / POLEPAIRS / commutation_time_save * 10;

    // �����ת��ʱ����Ҫ���ٶ�ȡ��
    if(FORWARD == motor_control.spin_dir)
    {
        move_filter_calc(&speed_filter, speed);
    }
    else
    {
        move_filter_calc(&speed_filter, -speed);
    }


}
//-------------------------------------------------------------------------------------------------------------------
// �������     ���ദ�� ��������һ��λ�ȴ���ʱ��
// ����˵��     void
// ʹ��ʾ��     phase_change_manage();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void phase_change_manage(void)
{
    commutation_time_save = system_getval();
    system_start();

    calc_speed();
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ���೬ʱ����
// ����˵��     void
// ʹ��ʾ��     phase_change_time_check();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void phase_change_time_check(void)
{
    if(system_getval() > (COMMUTATION_TIMEOUT * 1000))
    {
        commutation_time_save = COMMUTATION_TIMEOUT;

        move_filter_init(&speed_filter);                            // ����ƽ���˲���ʼ��
        motor_control.run_state = MOTOR_STOP;
    }
    else
    {
        motor_control.run_state = MOTOR_RUN;
    }
}


//-------------------------------------------------------------------------------------------------------------------
// �������     ���ת���������
// ����˵��     void
// ʹ��ʾ��     motor_dir_out();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_dir_out(void)
{
    switch(spe_g.hall_now)
    {
        case 1:
        {
            if      (spe_g.hall_last == 3) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 5) motor_control.spin_dir = REVERSE;
            break;
        }
        case 2:
        {
            if      (spe_g.hall_last == 6) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 3) motor_control.spin_dir = REVERSE;
            break;
        }
        case 3:
        {
            if      (spe_g.hall_last == 2) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 1) motor_control.spin_dir = REVERSE;
            break;
        }
        case 4:
        {
            if      (spe_g.hall_last == 5) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 6) motor_control.spin_dir = REVERSE;
            break;
        }
        case 5:
        {
            if      (spe_g.hall_last == 1) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 4) motor_control.spin_dir = REVERSE;
            break;
        }
        case 6:
        {
            if      (spe_g.hall_last == 4) motor_control.spin_dir = FORWARD;
            else if (spe_g.hall_last == 2) motor_control.spin_dir = REVERSE;
            break;
        }
    }

    gpio_set_level(MOTOR_DIR_OUT_PIN, motor_control.spin_dir);
}


//-------------------------------------------------------------------------------------------------------------------
// �������     ����ٶ����
// ����˵��     void
// ʹ��ʾ��     motor_speed_out();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_speed_out(void)
{
    motor_control.motor_speed = speed_filter.data_average;

    if(motor_control.motor_speed)
    {
        pwm_set_freq(MOTOR_SPEED_OUT_PIN, func_abs(motor_control.motor_speed), 5000);           // Ƶ�ʸ��ĺ�����δ�ڿ�Դ����д�� ��Ҫʹ�õ�ͬѧ���н��˺������µ���Դ��
    }
    else
    {
        pwm_set_freq(MOTOR_SPEED_OUT_PIN, 1000, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ���״̬���
// ����˵��     void
// ʹ��ʾ��     motor_check();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_check(void)
{
    static float motor_protect_current = 0;
    static uint8 last_brake_flag = 0;

    motor_protect_current = (motor_protect_current * 19 +  adc_information.voltage_bus) / 20;   // ��ĸ�ߵ�����ͨ�˲�

    if(motor_protect_current > MOTOR_LOCKED_VALUE || motor_control.locked_rotor == 1)           // ĸ�ߵ���������ת��ֵ
    {
        motor_control.locked_rotor = 1;
        spe_g.speed.duty = 0;
    }

    last_brake_flag = motor_control.brake_flag;                         // ������һ�ε�ɲ��״̬

    if(spe_g.speed.duty == 0 || motor_control.locked_rotor == 1)        // ��ռ�ձ�Ϊ0���߶�תʱ��ɲ����־λ��λ�����ռ�ձ�
    {
        spe_g.speed.duty = 0;
        motor_control.brake_flag = 1;
    }
    else
    {
        motor_control.brake_flag = 0;
#if BATTERY_PROTECT == 1
        if(motor_control.battery_state == LOW_VOLTAGE)                  // ����ѹ����ʱ��ɲ����־λ��λ�����ռ�ձ�
        {
            spe_g.speed.duty = 0;
            motor_control.brake_flag = 1;
        }
#endif
    }

    if(last_brake_flag != motor_control.brake_flag)                     // ���ɲ����־λ�б仯���������������
    {
#if BLDC_BRAKE_ENABLE == 1                                              // ����ɲ��
        advance_switch();
#endif
    }

}


//-------------------------------------------------------------------------------------------------------------------
// �������     ���������ʼ��
// ����˵��     void
// ʹ��ʾ��     motor_init();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void motor_init(void)
{
    motor_control.en_status  = gpio_get_level(EN_PIN);              // ��ȡ��ǰʹ��״̬
    motor_control.run_model  = USER_INPUT;                          // ��ʼĬ��Ϊ�û�����ģʽ
    motor_control.set_dir    = gpio_get_level(MOTOR_DIR_IN_PIN);    // ��ȡ������Ϣ
    motor_control.brake_flag = 0;
    advance_switch();

}
