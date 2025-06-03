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
 * �ļ�����          gpio
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

#include "gpio.h"
#include "motor.h"
#include "zf_driver_delay.h"
#include "zf_driver_pwm.h"

uint8 key_status = 1;    // ��ǰ����״̬
uint8 key_last_status;   // ��һ�ΰ���״̬
uint8 key_flag;          // ����������־λ


void led_init(void)
{
    gpio_init(LED_RUN_PIN, GPO, 1, GPO_PUSH_PULL);     // ��ʼ������ָʾ��
    gpio_init(LED_ERR_PIN, GPO, 1, GPO_PUSH_PULL);     // ��ʼ������ָʾ��
    gpio_init(LED_MODEL_PIN, GPO, 1, GPO_PUSH_PULL);   // ��ʼ��ģʽָʾ��
    gpio_init(EN_PIN, GPI, 1, GPI_PULL_UP);            // ��ʼ��ʹ�ܿ���
}

void led_output(void)
{
    // ��ӵ�����Ϣ���
    // printf("���ϼ��: EN_FSOI=%d, EN=%d, ���״̬=%d, ��ת=%d\n",
    //        gpio_get_level(EN_FSOI_PIN),
    //        gpio_get_level(EN_PIN),
    //        motor_control.battery_state,
    //        motor_control.locked_rotor);
    if (!gpio_get_level(EN_FSOI_PIN) && !gpio_get_level(EN_PIN))
    {
        if (motor_control.run_state == MOTOR_RUN)
        {
            gpio_set_level(LED_RUN_PIN, 0);   // �������е�
        }
        else
        {
            gpio_set_level(LED_RUN_PIN, 1);   // �ر����е�
        }
    }
    else
    {
        gpio_set_level(LED_RUN_PIN, 1);   // �ر����е�
    }

    if ((gpio_get_level(EN_FSOI_PIN) && !gpio_get_level(EN_PIN)) || motor_control.battery_state == LOW_VOLTAGE ||
        motor_control.locked_rotor)
    {
        gpio_set_level(LED_ERR_PIN, 0);   // �������ϵ�
    }
    else
    {
        gpio_set_level(LED_ERR_PIN, 1);   // �رչ��ϵ�
    }

    if (motor_control.run_model)
    {
        gpio_set_level(LED_MODEL_PIN, 1);
    }
    else
    {
        gpio_set_level(LED_MODEL_PIN, 0);
    }
}

void bldc_key_init(void)
{
    gpio_init(KEY, GPI, 1, GPI_PULL_UP);
}

void bldc_key_scan(void)
{
    // ʹ�ô˷����ŵ����ڣ�����Ҫʹ��while(1) �ȴ������⴦������Դ�˷�
    // ���水��״̬
    key_last_status = key_status;
    // ��ȡ��ǰ����״̬
    key_status = gpio_get_level(KEY);
    // ����ɿ������Ķ�����   ��λ��־λ
    if (key_status && !key_last_status)
    {
        key_flag = 1;
    }
    // ��־λ ��λ ֮�󣬿���ʹ�ñ�־λִ���Լ���Ҫ�����¼�
    if (key_flag == 1)
    {
        key_flag = 0;   // ʹ�ð���֮��Ӧ�������־λ

        if (motor_control.run_model == USER_INPUT)
        {
            motor_control.run_model = BOARD_POTENTIOMET;
        }
        else
        {
            motor_control.run_model = USER_INPUT;
        }
    }
}
