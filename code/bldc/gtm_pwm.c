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
* �ļ�����          gtm_pwm
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
#include "motor.h"
#include "pwm_input.h"
#include "gtm_pwm.h"

spe_st spe_g;


//-------------------------------------------------------------------------------------------------------------------
// �������     GTMģ��ʱ������
// ����˵��     void
// ʹ��ʾ��     clock_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void clock_cfg(void)
{
    IfxGtm_enable(&MODULE_GTM);

    GTM_CMU_CLK_EN.U                    = CMU_CLK_ALL_DISABLE;

    GTM_CMU_GCLK_NUM.B.GCLK_NUM         = 1;                        // ��Ƶϵ���ķ���
    GTM_CMU_GCLK_DEN.B.GCLK_DEN         = 1;                        // ��Ƶϵ���ķ�ĸ

    GTM_CMU_CLK_0_CTRL.B.CLK_CNT        = 0;                        // ��Ƶϵ��
    GTM_CMU_CLK_1_CTRL.B.CLK_CNT        = 0;
    GTM_CMU_FXCLK_CTRL.B.FXCLK_SEL      = 0;                        // ѡ��FXCLK��ʱ����Դ

    GTM_CMU_CLK_EN.B.EN_CLK0            = CMU_CLK_ENABLE;
    GTM_CMU_CLK_EN.B.EN_CLK1            = CMU_CLK_ENABLE;
    GTM_CMU_CLK_EN.B.EN_FXCLK           = CMU_CLK_ENABLE;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     GTMģ���ж�ˢ��
// ����˵��     void
// ʹ��ʾ��     ccm_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void ccm_cfg(void)
{
    GTM_CTRL.B.RF_PROT                  = TRUE;                     // �ر�ȫ���ж� 1���ر�
    GTM_CTRL.B.RF_PROT                  = FALSE;                    // ����ȫ���ж� 0������
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�����������Լ�ɲ������
// ����˵��     void
// ʹ��ʾ��     hall_tim_input_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void hall_tim_input_cfg(void)
{
    IfxGtm_PinMap_setTimTin(&HALL_A, IfxPort_InputMode_pullUp);     // ���û���ͨ��Ϊ��������ģʽ
    IfxGtm_PinMap_setTimTin(&HALL_B, IfxPort_InputMode_pullUp);
    IfxGtm_PinMap_setTimTin(&HALL_C, IfxPort_InputMode_pullUp);

    IfxGtm_PinMap_setTimTin(&FSOI_PIN, IfxPort_InputMode_pullDown);

    GTM_TIM0_CH0_CTRL.B.CICTRL = IfxGtm_Tim_Input_currentChannel;   // ʹ�õ�ǰͨ��
    GTM_TIM0_IN_SRC.B.MODE_0   = 0;
    GTM_TIM0_IN_SRC.B.VAL_0    = 0;

    GTM_TIM0_CH1_CTRL.B.CICTRL = IfxGtm_Tim_Input_currentChannel;   // ʹ�õ�ǰͨ��
    GTM_TIM0_IN_SRC.B.MODE_1   = 0;
    GTM_TIM0_IN_SRC.B.VAL_1    = 0;

    GTM_TIM0_CH2_CTRL.B.CICTRL = IfxGtm_Tim_Input_currentChannel;   // ʹ�õ�ǰͨ��
    GTM_TIM0_IN_SRC.B.MODE_2   = 0;
    GTM_TIM0_IN_SRC.B.VAL_2    = 0;


    GTM_TIM0_CH0_CTRL.B.CLK_SEL      = IfxGtm_Cmu_Clk_0;
    GTM_TIM0_CH0_CTRL.B.FLT_CNT_FRQ  = IfxGtm_Cmu_Tim_Filter_Clk_0;                     // �˲�����Ƶ��ѡ��
    GTM_TIM0_CH0_CTRL.B.FLT_EN       = TRUE;                                            // �˲�ʹ��
    GTM_TIM0_CH0_CTRL.B.FLT_MODE_FE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �½����˲�ģʽ ����
    GTM_TIM0_CH0_CTRL.B.FLT_MODE_RE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �Ͻ����˲�ģʽ ����
    GTM_TIM0_CH0_CTRL.B.FLT_CTR_FE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH0_CTRL.B.FLT_CTR_RE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH0_FLT_FE.B.FLT_FE     = FILTER_CON_NUM;                                  // �����˲�����ֵ
    GTM_TIM0_CH0_FLT_RE.B.FLT_RE     = FILTER_CON_NUM;

    GTM_TIM0_CH1_CTRL.B.CLK_SEL      = IfxGtm_Cmu_Clk_0;
    GTM_TIM0_CH1_CTRL.B.FLT_CNT_FRQ  = IfxGtm_Cmu_Tim_Filter_Clk_0;                     // �˲�����Ƶ��ѡ��
    GTM_TIM0_CH1_CTRL.B.FLT_EN       = TRUE;                                            // �˲�ʹ��
    GTM_TIM0_CH1_CTRL.B.FLT_MODE_FE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �½����˲�ģʽ ����
    GTM_TIM0_CH1_CTRL.B.FLT_MODE_RE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �Ͻ����˲�ģʽ ����
    GTM_TIM0_CH1_CTRL.B.FLT_CTR_FE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH1_CTRL.B.FLT_CTR_RE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH1_FLT_FE.B.FLT_FE     = FILTER_CON_NUM;                                  // �����˲�����ֵ
    GTM_TIM0_CH1_FLT_RE.B.FLT_RE     = FILTER_CON_NUM;

    GTM_TIM0_CH2_CTRL.B.CLK_SEL      = IfxGtm_Cmu_Clk_0;
    GTM_TIM0_CH2_CTRL.B.FLT_CNT_FRQ  = IfxGtm_Cmu_Tim_Filter_Clk_0;                     // �˲�����Ƶ��ѡ��
    GTM_TIM0_CH2_CTRL.B.FLT_EN       = TRUE;                                            // �˲�ʹ��
    GTM_TIM0_CH2_CTRL.B.FLT_MODE_FE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �½����˲�ģʽ ����
    GTM_TIM0_CH2_CTRL.B.FLT_MODE_RE  = IfxGtm_Tim_FilterMode_individualDeglitchTime;    // �Ͻ����˲�ģʽ ����
    GTM_TIM0_CH2_CTRL.B.FLT_CTR_FE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH2_CTRL.B.FLT_CTR_RE   = IfxGtm_Tim_FilterCounter_upDown;                 // ��ҪFLT_MODE_RE����Ϊ1����Ч
    GTM_TIM0_CH2_FLT_FE.B.FLT_FE     = FILTER_CON_NUM;                                  // �����˲�����ֵ
    GTM_TIM0_CH2_FLT_RE.B.FLT_RE     = FILTER_CON_NUM;

    GTM_TIM0_CH0_CTRL.B.TIM_MODE     = IfxGtm_Tim_Mode_inputEvent;                      // �����¼�
    GTM_TIM0_CH0_CTRL.B.ISL          = TRUE;                                            // ˫���ش���
    GTM_TIM0_CH0_CTRL.B.TIM_EN       = TRUE;                                            // ʹ��
    GTM_TIM0_CH1_CTRL.B.TIM_MODE     = IfxGtm_Tim_Mode_inputEvent;
    GTM_TIM0_CH1_CTRL.B.ISL          = TRUE;
    GTM_TIM0_CH1_CTRL.B.TIM_EN       = TRUE;
    GTM_TIM0_CH2_CTRL.B.TIM_MODE     = IfxGtm_Tim_Mode_inputEvent;
    GTM_TIM0_CH2_CTRL.B.ISL          = TRUE;
    GTM_TIM0_CH2_CTRL.B.TIM_EN       = TRUE;

#if BOARD_OVER_CURRENT == 1
    //FSOI���ţ���Ҫ���ڿ��ٹر����
    GTM_TIM1_CH6_CTRL.B.TIM_MODE     = IfxGtm_Tim_Mode_inputEvent;
    GTM_TIM1_CH6_CTRL.B.ISL          = TRUE;
    GTM_TIM1_CH6_CTRL.B.TIM_EN       = TRUE;
#endif
}

//-------------------------------------------------------------------------------------------------------------------
// �������     SPE0ģ�������������
// ����˵��     void
// ʹ��ʾ��     spe0_pattern_init_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_pattern_init_cfg (void)
{
    spe_g.start_pattern = GTM_SPE0_CTRL_STAT.B.NIP;

    switch (spe_g.start_pattern)
    {
        case HALL_HARDWARE_ORDER_0:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_0;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_5;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_0;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_0;
            break;
        case HALL_HARDWARE_ORDER_1:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_1;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_0;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_1;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_1;
            break;
        case HALL_HARDWARE_ORDER_2:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_2;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_1;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_2;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_2;
            break;
        case HALL_HARDWARE_ORDER_3:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_3;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_2;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_3;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_3;
            break;
        case HALL_HARDWARE_ORDER_4:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_4;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_3;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_4;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_4;
            break;
        case HALL_HARDWARE_ORDER_5:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_5;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_4;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_5;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_5;
            break;
        default:
            break;
    }
    spe_g.pattern_first.Pattern_AIP[spe_g.pattern_first.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.AIP;
    spe_g.pattern_first.Pattern_NIP[spe_g.pattern_first.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.NIP;
    spe_g.pattern_first.Pattern_PIP[spe_g.pattern_first.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.PIP;
    spe_g.pattern_first.Pattern_PTR[spe_g.pattern_first.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR;
    spe_g.pattern_first.pattern_cnt ++;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     SPE0ģ���������
// ����˵��     void
// ʹ��ʾ��     clock_cfg();
// ��ע��Ϣ     ���ڻ���������ʱ������ˢ��
//-------------------------------------------------------------------------------------------------------------------
void spe0_pattern_cfg (void)
{
    spe_g.start_pattern = GTM_SPE0_CTRL_STAT.B.NIP;

    switch (spe_g.start_pattern)
    {
        case HALL_HARDWARE_ORDER_0:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_0;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_5;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_0;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_0;
            break;
        case HALL_HARDWARE_ORDER_1:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_1;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_0;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_1;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_1;
            break;
        case HALL_HARDWARE_ORDER_2:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_2;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_1;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_2;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_2;
            break;
        case HALL_HARDWARE_ORDER_3:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_3;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_2;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_3;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_3;
            break;
        case HALL_HARDWARE_ORDER_4:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_4;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_3;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_4;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_4;
            break;
        case HALL_HARDWARE_ORDER_5:
            GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR        = PAT_PTR_5;
            GTM_SPE0_CTRL_STAT.B.PIP                = HALL_HARDWARE_ORDER_4;
            GTM_SPE0_CTRL_STAT.B.AIP                = HALL_HARDWARE_ORDER_5;
            GTM_SPE0_OUT_CTRL.B.SPE_OUT_CTRL        = MOTOR_FOREWARD_5;
            break;
        default:
            break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// �������     SPE0ģ���ж�����
// ����˵��     void
// ʹ��ʾ��     spe0_irq_init();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_irq_init(void)
{
    IfxSrc_init(&SRC_GTMSPE0IRQ, SRC_CPU0, SRC_SPE_INT_PRIO);       // ����SPE���ж����ȼ� �Լ������жϵ�CPU
    IfxSrc_enable(&SRC_GTMSPE0IRQ);                                 // �ж�ʹ��

    GTM_SPE0_IRQ_EN.U   = SRC_ENABLE_ALL;                           // SPEģ���ж�ʹ��
    GTM_SPE0_EIRQ_EN.U  = SRC_ENABLE_ALL;                           // �����ж�ʹ��
    GTM_SPE0_IRQ_MODE.U = SRC_PULSE_NOTIFY;                         // �ж�����
}

//-------------------------------------------------------------------------------------------------------------------
// �������     SPE0ģ���ͨ����ʼ��
// ����˵��     void
// ʹ��ʾ��     spe0_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_cfg (void)
{
    spe0_irq_init();

    GTM_SPE0_PAT.B.IP0_VAL = VALID_IN_PATTERN;      // ����ģʽ��Ч
    GTM_SPE0_PAT.B.IP1_VAL = VALID_IN_PATTERN;
    GTM_SPE0_PAT.B.IP2_VAL = VALID_IN_PATTERN;
    GTM_SPE0_PAT.B.IP3_VAL = VALID_IN_PATTERN;
    GTM_SPE0_PAT.B.IP4_VAL = VALID_IN_PATTERN;
    GTM_SPE0_PAT.B.IP5_VAL = VALID_IN_PATTERN;
    GTM_SPE0_PAT.B.IP6_VAL = INVALID_IN_PATTERN;    // ����ģʽ��Ч
    GTM_SPE0_PAT.B.IP7_VAL = INVALID_IN_PATTERN;


    GTM_SPE0_PAT.B.IP0_PAT = HALL_HARDWARE_ORDER_0; // ����TIMx y z��������ֵ  ʵ�ʾ��ǻ�������ֵ
    GTM_SPE0_PAT.B.IP1_PAT = HALL_HARDWARE_ORDER_1;
    GTM_SPE0_PAT.B.IP2_PAT = HALL_HARDWARE_ORDER_2;
    GTM_SPE0_PAT.B.IP3_PAT = HALL_HARDWARE_ORDER_3;
    GTM_SPE0_PAT.B.IP4_PAT = HALL_HARDWARE_ORDER_4;
    GTM_SPE0_PAT.B.IP5_PAT = HALL_HARDWARE_ORDER_5;
    GTM_SPE0_PAT.B.IP6_PAT = 0;//��Чֵ
    GTM_SPE0_PAT.B.IP7_PAT = 0;

    motor_control.set_dir = gpio_get_level(MOTOR_DIR_IN_PIN);

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
    GTM_SPE0_OUT_PAT6.U = 0x0;                      // ��Чֵ
    GTM_SPE0_OUT_PAT7.U = 0x0;

    // ÿ����10�δ����жϣ���Ҫ�����Ǳ���ͨ��һ������ʱ��ȥ�����ٶȣ��Ӷ����¼�����ٶ��ǲ����ġ�
    // �ٶȲ�������Ϊ������װ���µĻ���ʱ���ǲ�һ���ġ�
    GTM_SPE0_CMP.B.CMP = REV_CNT_VAL & 0xFFFFFF;
    spe0_pattern_init_cfg();

    GTM_SPE0_CTRL_STAT.B.SPE_EN   = TRUE;
    GTM_SPE0_CTRL_STAT.B.SIE0     = TRUE;                               // xͨ��ʹ��
    GTM_SPE0_CTRL_STAT.B.SIE1     = TRUE;                               // yͨ��ʹ��
    GTM_SPE0_CTRL_STAT.B.SIE2     = TRUE;                               // zͨ��ʹ��
#if BOARD_OVER_CURRENT == 1
    GTM_SPE0_CTRL_STAT.B.FSOM     = 1;                                  // ���ٹر�ģʽʹ��
#endif
    GTM_SPE0_CTRL_STAT.B.PDIR     = 0;
    GTM_SPE0_CTRL_STAT.B.ADIR     = 0;
    GTM_SPE0_CTRL_STAT.B.FSOL     = 0xFF;                               // �رյ�ʱ��8��ͨ�������ֵ�趨
    GTM_SPE0_CTRL_STAT.B.TRIG_SEL = 2;                                  // ʹ��TOM[i] CH1��ʱ��������
    GTM_SPE0_CTRL_STAT.B.TIM_SEL  = 0;                                  // ʹ��TIM0 ͨ��0-ͨ��2��ΪSPE����
}

//-------------------------------------------------------------------------------------------------------------------
// �������     SPE0-TOMģ���ͨ������
// ����˵��     void
// ʹ��ʾ��     spe0_tom_tgc_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_tom_tgc_cfg (void)
{
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL0 = FORCE_UPDATE_EN  & 0x3;      // ǿ�Ƹ���
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL2 = FORCE_UPDATE_EN  & 0x3;
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL1 = FORCE_UPDATE_DIS & 0x3;      // ����
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL3 = FORCE_UPDATE_DIS & 0x3;
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL4 = FORCE_UPDATE_DIS & 0x3;
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL5 = FORCE_UPDATE_DIS & 0x3;
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL6 = FORCE_UPDATE_DIS & 0x3;
    GTM_TOM0_TGC0_FUPD_CTRL.B.FUPD_CTRL7 = FORCE_UPDATE_DIS & 0x3;

    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL0 = TOM_OUTPUT_ENABLE & 0x3;   // �ڸ��´�����ʱ��ʹ�����
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL1 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL2 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL3 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL4 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL5 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL6 = TOM_OUTPUT_ENABLE & 0x3;
    GTM_TOM0_TGC0_OUTEN_CTRL.B.OUTEN_CTRL7 = TOM_OUTPUT_ENABLE & 0x3;

    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL0 = ENDIS_EN;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL2 = ENDIS_EN;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL1 = ENDIS_DIS;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL3 = ENDIS_DIS;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL4 = ENDIS_DIS;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL5 = ENDIS_DIS;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL6 = ENDIS_DIS;
    GTM_TOM0_TGC0_ENDIS_CTRL.B.ENDIS_CTRL7 = ENDIS_DIS;

    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL0 = ENDIS_EN  & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL2 = ENDIS_EN  & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL1 = ENDIS_DIS & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL3 = ENDIS_DIS & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL4 = ENDIS_DIS & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL5 = ENDIS_DIS & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL6 = ENDIS_DIS & 0x3;
    GTM_TOM0_TGC0_GLB_CTRL.B.UPEN_CTRL7 = ENDIS_DIS & 0x3;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ��TOM0���ģ��
// ����˵��     void
// ʹ��ʾ��     spe0_pwm_tom_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_pwm_tom_cfg (void)
{
    spe0_tom_tgc_cfg ();

    GTM_TOM0_CH2_CTRL.B.OSM        = 1;                 // �����ر�one shot mode
    GTM_TOM0_CH2_CTRL.B.SPEM       = 1;
    GTM_TOM0_CH2_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;
    GTM_TOM0_CH2_SR0.U = 10;
    GTM_TOM0_CH2_SR1.U = 10;                            // �����ӳٻ���ʱ��

    GTM_TOM0_CH0_CTRL.B.SL         = TOM_CH_SL_HIGH;    // ռ�ձȱ�ʾ���Ǹߵ�ƽ��ռ��
    GTM_TOM0_CH0_CTRL.B.OSM        = OSM_DIS;           // �ر�one shot mode
    GTM_TOM0_CH0_CTRL.B.SPEM       = SPEM_DIS;
    GTM_TOM0_CH0_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH0_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;
    GTM_TOM0_CH0_CTRL.B.RST_CCU0   = CM0_MATCHING;

    spe_g.speed.duty   = 100;
    spe_g.speed.period = 5000;

    GTM_TOM0_CH0_SR1.U = spe_g.speed.duty;
    GTM_TOM0_CH0_SR0.U = spe_g.speed.period;

    GTM_TOM0_CH1_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH1_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH1_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH1_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_CH3_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH3_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH3_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH3_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_CH4_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH4_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH4_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH4_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_CH5_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH5_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH5_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH5_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_CH6_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH6_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH6_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH6_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_CH7_CTRL.B.OSM        = OSM_DIS;
    GTM_TOM0_CH7_CTRL.B.SPEM       = SPEM_EN;
    GTM_TOM0_CH7_CTRL.B.TRIGOUT    = TRIG_CCU0;
    GTM_TOM0_CH7_CTRL.B.CLK_SRC_SR = TOM_CH_CMU_FXCLK0;

    GTM_TOM0_TGC0_GLB_CTRL.B.HOST_TRIG = 1;             // �����TOMģ��ȫ�ִ�������
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ѡ�������������
// ����˵��     void
// ʹ��ʾ��     spe0_pwm_mux_outport_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void spe0_pwm_mux_outport_cfg(void)
{
    IfxGtm_PinMap_setTomTout(&PWM_PRODUCE_PIN,  IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&A_PHASE_PIN_H,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&A_PHASE_PIN_L,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&B_PHASE_PIN_H,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&B_PHASE_PIN_L,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&C_PHASE_PIN_H,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxGtm_PinMap_setTomTout(&C_PHASE_PIN_L,    IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed1);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     GTM�жϴ������
// ����˵��     void
// ʹ��ʾ��     pattern_chk();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
void pattern_chk(void)
{
    uint8 aip, nip, pip, ptr;
    aip = spe_g.pattern.Pattern_AIP[spe_g.pattern.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.AIP;
    nip = spe_g.pattern.Pattern_NIP[spe_g.pattern.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.NIP;
    pip = spe_g.pattern.Pattern_PIP[spe_g.pattern.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.PIP;
    ptr = spe_g.pattern.Pattern_PTR[spe_g.pattern.pattern_cnt] = GTM_SPE0_CTRL_STAT.B.SPE_PAT_PTR;
    spe_g.pattern.pattern_cnt ++;
    if (spe_g.pattern.pattern_cnt >= MAX_PATTERN)
    {
        spe_g.pattern.pattern_cnt = 0;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// �������     GTMģ���ʼ��
// ����˵��     void
// ʹ��ʾ��     clock_cfg();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
void gtm_bldc_init(void)
{
    clock_cfg();                // GTMģ��ʱ�����ó�ʼ��
    ccm_cfg();                  // GTM�ж�ˢ��
    hall_tim_input_cfg();       // ��ʼ�����������Լ�ɲ������
    spe0_cfg();                 // ��ʼ��SPE0ģ��ͨ��
    spe0_pwm_tom_cfg();         // ��ʼ��TOM0���ģ��
    spe0_pwm_mux_outport_cfg(); // ѡ���������PWM������
}
