#ifndef __TIMER_H
#define __TIMER_H
#include "system.h"
#include "systick.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//通用定时器 驱动代码			   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/12/03
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  


void Servo_Init(u16 arr,u16 psc);
void Trigger_Control(void);
void Trigger_Control1(void);
void Trigger_Control2(void);
void Trigger_Control3(void);
void shooting(void);
 
#endif
