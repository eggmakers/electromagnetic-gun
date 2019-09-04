#ifndef _STEPPER_H
#define _STEPPER_H

#include "system.h"
#include "SysTick.h"

#define DIR1_ON GPIO_SetBits(GPIOA,GPIO_Pin_3)
#define DIR1_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_3)

#define DIR2_ON GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define DIR2_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_4)

void go1(u16 pwm1);
void back1(u16 pwm2);
void go2(u16 pwm3);
void back2(u16 pwm4);
void stop(void);
void Stepper_Init(void);

#endif
