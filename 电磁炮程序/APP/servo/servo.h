#ifndef __TIMER_H
#define __TIMER_H
#include "system.h"
#include "systick.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//ͨ�ö�ʱ�� ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/12/03
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved
////////////////////////////////////////////////////////////////////////////////// 	  


void Servo_Init(u16 arr,u16 psc);
void Trigger_Control(void);
void Trigger_Control1(void);
void Trigger_Control2(void);
void Trigger_Control3(void);
void shooting(void);
 
#endif
