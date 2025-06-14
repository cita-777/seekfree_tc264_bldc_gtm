/*********************************************************************************************************************
 * TC264 Opensourec Library 即（TC264 开源库）是一个基于官方 SDK 接口的第三方开源库
 * Copyright (c) 2022 SEEKFREE 逐飞科技
 *
 * 本文件是 TC264 开源库的一部分
 *
 * TC264 开源库 是免费软件
 * 您可以根据自由软件基金会发布的 GPL（GNU General Public License，即 GNU通用公共许可证）的条款
 * 即 GPL 的第3版（即 GPL3.0）或（您选择的）任何后来的版本，重新发布和/或修改它
 *
 * 本开源库的发布是希望它能发挥作用，但并未对其作任何的保证
 * 甚至没有隐含的适销性或适合特定用途的保证
 * 更多细节请参见 GPL
 *
 * 您应该在收到本开源库的同时收到一份 GPL 的副本
 * 如果没有，请参阅<https://www.gnu.org/licenses/>
 *
 * 额外注明：
 * 本开源库使用 GPL3.0 开源许可证协议 以上许可申明为译文版本
 * 许可申明英文版在 libraries/doc 文件夹下的 GPL3_permission_statement.txt 文件中
 * 许可证副本在 libraries 文件夹下 即该文件夹下的 LICENSE 文件
 * 欢迎各位使用并传播本程序 但修改内容时必须保留逐飞科技的版权声明（即本声明）
 *
 * 文件名称          bldc_config
 * 公司名称          成都逐飞科技有限公司
 * 版本信息          查看 libraries/doc 文件夹内 version 文件 版本说明
 * 开发环境          ADS v1.8.0
 * 适用平台          TC264D
 * 店铺链接          https://seekfree.taobao.com/
 *
 * 修改记录
 * 日期              作者                备注
 * 2023-02-01       pudding             first version
 ********************************************************************************************************************/

#ifndef _BLDC_CONFIG_H
#define _BLDC_CONFIG_H

// 定义电机型号
// 1：R车 博思无刷电机
// 2：L车 科宇无刷电机
// 3：N车 飞轮无刷电机
// 4：N车 行进无刷电机
#define BLDC_MOTOR_TYPE (1)
// 0：不开启刹车功能     1：开启
#define BLDC_BRAKE_ENABLE (1)

// 0：不开启电池保护，电压过低仅亮起故障灯
// 1：开启电池保护，电压过低亮起故障灯并直接刹车(默认开启)
#define BATTERY_PROTECT (1)

// 0：不开启硬件过流保护
// 1：开启硬件过流保护
#define BOARD_OVER_CURRENT (1)

// 单节电池保护阈值(默认3.7V)     低于3.7V则认为过放(会对电池造成不可逆的损坏)  2S锂电池最低电压7.4V
// 3S锂电池最低电压11.1V
#define BATTERY_PROTECT_VALUE (3.7f)

// 堵转检测阈值(默认5A)   运行电流超过5A则触发堵转事件，将关闭输出并不再打开
#define MOTOR_LOCKED_VALUE (10.0f)






#endif
