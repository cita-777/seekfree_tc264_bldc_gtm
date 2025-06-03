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
#ifndef _gtm_pwm_h
#define _gtm_pwm_h

#include "_PinMap/IfxGtm_PinMap.h"
#include "bldc_config.h"
#include "zf_common_typedef.h"

#define MAX_PATTERN 61

#define CMU_CLK_ALL_DISABLE     (0x55555555)    // ʱ��ȫ��ʧ��
#define CMU_CLK_ENABLE          (2)             // ʱ��ʹ��

#define VALID_IN_PATTERN        (1u)
#define INVALID_IN_PATTERN      (0u)
// TOM����ź�ģʽѡ��
#define PAT_PTR_0               (0u)
#define PAT_PTR_1               (1u)
#define PAT_PTR_2               (2u)
#define PAT_PTR_3               (3u)
#define PAT_PTR_4               (4u)
#define PAT_PTR_5               (5u)

// ����Ӳ��˳��    6 2 3 1 5 4
#define HALL_HARDWARE_ORDER_0   (5u)
#define HALL_HARDWARE_ORDER_1   (1u)
#define HALL_HARDWARE_ORDER_2   (3u)
#define HALL_HARDWARE_ORDER_3   (2u)
#define HALL_HARDWARE_ORDER_4   (6u)
#define HALL_HARDWARE_ORDER_5   (4u)
#if BLDC_MOTOR_TYPE == 1
// �����ת
#define MOTOR_FOREWARD_0        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_FOREWARD_1        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_FOREWARD_2        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_FOREWARD_3        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_FOREWARD_4        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_FOREWARD_5        (0xAE8A)    // A����B���ſ����������ر�
// �����ת
#define MOTOR_REVERSAL_0        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_REVERSAL_1        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_REVERSAL_2        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_REVERSAL_3        (0xAE8A)    // A����B���ſ����������ر�
#define MOTOR_REVERSAL_4        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_REVERSAL_5        (0xE8AA)    // B����C���ſ����������ر�
#endif
#if BLDC_MOTOR_TYPE == 2
// �����ת
#define MOTOR_FOREWARD_0        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_FOREWARD_1        (0xAE8A)    // A����B���ſ����������ر�
#define MOTOR_FOREWARD_2        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_FOREWARD_3        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_FOREWARD_4        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_FOREWARD_5        (0x8AEA)    // C����A���ſ����������ر�
// �����ת
#define MOTOR_REVERSAL_0        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_REVERSAL_1        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_REVERSAL_2        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_REVERSAL_3        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_REVERSAL_4        (0xAE8A)    // A����B���ſ����������ر�
#define MOTOR_REVERSAL_5        (0xEA8A)    // A����C���ſ����������ر�
#endif
#if BLDC_MOTOR_TYPE == 3
// �����ת
#define MOTOR_FOREWARD_0        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_FOREWARD_1        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_FOREWARD_2        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_FOREWARD_3        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_FOREWARD_4        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_FOREWARD_5        (0xAE8A)    // A����B���ſ����������ر�
// �����ת
#define MOTOR_REVERSAL_0        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_REVERSAL_1        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_REVERSAL_2        (0xAE8A)    // A����B���ſ����������ر�
#define MOTOR_REVERSAL_3        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_REVERSAL_4        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_REVERSAL_5        (0xA8EA)    // B����A���ſ����������ر�
#endif
#if BLDC_MOTOR_TYPE == 4
// �����ת
#define MOTOR_FOREWARD_0        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_FOREWARD_1        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_FOREWARD_2        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_FOREWARD_3        (0x8AEA)    // C����A���ſ����������ر�
#define MOTOR_FOREWARD_4        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_FOREWARD_5        (0xAE8A)    // A����B���ſ����������ر�
// �����ת
#define MOTOR_REVERSAL_0        (0x8EAA)    // C����B���ſ����������ر�
#define MOTOR_REVERSAL_1        (0xAE8A)    // A����B���ſ����������ر�
#define MOTOR_REVERSAL_2        (0xEA8A)    // A����C���ſ����������ر�
#define MOTOR_REVERSAL_3        (0xE8AA)    // B����C���ſ����������ر�
#define MOTOR_REVERSAL_4        (0xA8EA)    // B����A���ſ����������ر�
#define MOTOR_REVERSAL_5        (0x8AEA)    // C����A���ſ����������ر�
#endif

#define MOTOR_BRAKE             (0xEEEA)    // ɲ��


#define REV_CNT_VAL             (10u)       // ����̶����������ж�
#define FILTER_CON_NUM          (10u)       // �����źŵ��˲�ʱ������Ҫ������ȥ��ë��

#define FORCE_UPDATE_EN         (2)         //  ������ƼĴ���ǿ�Ƹ���
#define FORCE_UPDATE_DIS        (1)         //  ���Ը���

#define TOM_OUTPUT_ENABLE       (2)         //  ���ͨ��ʹ��
#define TOM_OUTPUT_DISABLE      (1)         //  ���ͨ��ʧ��

#define ENDIS_EN                (2)         //  ����ʹ��
#define ENDIS_DIS               (1)         //  ����ʧ��

#define TOM_CH_SL_LOW           (0)
#define TOM_CH_SL_HIGH          (1)
#define OSM_EN                  (1)
#define OSM_DIS                 (0)
#define SPEM_EN                 (1)
#define SPEM_DIS                (0)
#define CM0_MATCHING            (0)
#define TRIG_0_MATCHING         (1)
#define TRIG_0_EXT_TRIG         (0)

#define TRIG_CCU0               (1)
#define TRIG_BEFORE             (0)

#define TOM_CH_CMU_FXCLK0       (0)

#define SRC_SPE_INT_PRIO        (90)
#define SRC_PULSE_NOTIFY        (2U)
#define SRC_ENABLE_ALL          (0x1F)
#define SRC_CPU0                (0)
#define SRC_ENABLE              (1)

#define FCY                     ((uint32)100000000)                 // ģ��ʱ��
#define FPWM                    ((uint16)20000)                     // PWMƵ��
#define PWM_PRIOD_LOAD          (uint16)(5000)                      // PWM����װ��ֵ


// ��������Ϊʵ�������������
#define HALL_A                  (IfxGtm_TIM0_2_TIN33_P33_11_IN )    // �����ź�A������
#define HALL_B                  (IfxGtm_TIM0_0_TIN34_P33_12_IN )    // �����ź�B������
#define HALL_C                  (IfxGtm_TIM0_1_TIN35_P33_13_IN )    // �����ź�C������
#define FSOI_PIN                (IfxGtm_TIM1_6_TIN66_P20_10_IN )    // ɲ���ź����루���ٹرգ�
#define PWM_PRODUCE_PIN         (IfxGtm_TOM0_0_TOUT26_P33_4_OUT)    // PWM��������
#define A_PHASE_PIN_H           (IfxGtm_TOM0_2_TOUT28_P33_6_OUT)    // ���A�����ſ�������
#define A_PHASE_PIN_L           (IfxGtm_TOM0_3_TOUT29_P33_7_OUT)    // ���A�����ſ�������
#define B_PHASE_PIN_H           (IfxGtm_TOM0_4_TOUT30_P33_8_OUT)    // ���B�����ſ�������
#define B_PHASE_PIN_L           (IfxGtm_TOM0_5_TOUT40_P32_4_OUT)    // ���B�����ſ�������
#define C_PHASE_PIN_H           (IfxGtm_TOM0_6_TOUT42_P23_1_OUT)    // ���B�����ſ�������
#define C_PHASE_PIN_L           (IfxGtm_TOM0_7_TOUT64_P20_8_OUT)    // ���B�����ſ�������


typedef struct
{
    uint32 period;
    uint32 duty;
} speed_st;

typedef struct
{
    uint8 Pattern_AIP[MAX_PATTERN];
    uint8 Pattern_NIP[MAX_PATTERN];
    uint8 Pattern_PIP[MAX_PATTERN];
    uint8 Pattern_PTR[MAX_PATTERN];
    uint8 pattern_cnt;
} pattern_st;

typedef struct
{
    uint32 spe_rcmp; /* SPE revolution counter match event */
    uint32 spe_dchg; /* SPE_DIR bit changed on behalf of new input pattern */
    uint32 spe_perr; /* Wrong or invalid pattern detected at input */
    uint32 spe_bis;  /* Bouncing input signal detected */
    uint32 spe_nipd; /* New input pattern interrupt occurred */
} irq_st;

typedef struct
{
    speed_st    speed;
    pattern_st  pattern;
    pattern_st  pattern_first;
    irq_st      irqcnt;
    uint8       start_pattern;
    uint8       hall_last;
    uint8       hall_now;
} spe_st;


extern spe_st spe_g;

void spe0_pattern_cfg (void);
void pattern_chk(void);
void gtm_bldc_init(void);


#endif

