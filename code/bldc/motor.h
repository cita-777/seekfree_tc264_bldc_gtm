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

#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "zf_common_typedef.h"
#include "zf_driver_gpio.h"
#include "zf_driver_pwm.h"
#include "gtm_pwm.h"



#define MOTOR_SPEED_OUT_PIN (ATOM1_CH2_P21_4)   // �����ת�ٶ��������
#define MOTOR_DIR_OUT_PIN   (P21_5          )   // ������з����������

#define COMMUTATION_TIMEOUT (5000           )   // ���೬ʱʱ��  ��λ��10us

#define POLEPAIRS           (1              )   // ���������

#define PWM_PIT_NUM         (60*FPWM        )

typedef enum
{
    REVERSE,                                    // ��ת
    FORWARD,                                    // ��ת
}motor_dir_enum;

typedef enum
{
    MOTOR_ENABLE,                               // ����ʹ��
    MOTOR_DISABLE,                              // �����ر�
}motor_en_state_enum;

typedef enum
{
    MOTOR_STOP,                                 // ���δ����
    MOTOR_RUN,                                  // �����������
}motor_run_state_enum;

typedef enum
{
    USER_INPUT,                                 // �û�����ģʽ   ͨ���û������PWMռ�ձȺ�DIR�źſ��Ƶ��
    BOARD_POTENTIOMET,                          // ���ص�λ��ģʽ  ʹ���������ϵĵ�λ������ת�� ������DIR���ſ���
}motor_run_model_enum;

typedef enum
{
    NORMAL_VOLTAGE,                             // ��ص�ѹ����
    LOW_VOLTAGE,                                // ��ص�ѹ����
    NO_BATTERY,                                 // δ���ӵ��
}battery_state_enum;

typedef struct
{
    motor_en_state_enum     en_status;          // ���ʹ��״̬
    uint8                   brake_flag;         // ���ɲ����־λ          1������ɲ��  0��δ����ɲ��
    motor_run_model_enum    run_model;          // �������ģʽ           USER_INPUT���û�����  BOARD_POTENTIOMET����λ������
    motor_run_state_enum    run_state;          // �������״̬
    uint8                   locked_rotor;       // ����Ƿ��ת           1�������ת  0�����������ת
    motor_dir_enum          set_dir;            // �����ǰ���÷���        FORWARD����ת  REVERSE����ת
    motor_dir_enum          spin_dir;           // �����ǰ��ת����        FORWARD����ת  REVERSE����ת
    int32                   motor_speed;        // �����ǰת��
    battery_state_enum      battery_state;      // ��ص�ǰ״̬

}motor_struct;


extern motor_struct motor_control;
extern uint8 phase_change;

void motor_information_out_init(void);
void motor_set_dir(void);
void speed_ctrl(speed_st speed);
void advance_switch(void);
void phase_change_manage(void);
void phase_change_time_check(void);
void motor_dir_out(void);
void motor_speed_out(void);
void motor_check(void);
void motor_init(void);

#endif /* CODE_MOTOR_H_ */
