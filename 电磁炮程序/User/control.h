#ifndef _CONTROL_H
#define _CONTROL_H

#include "system.h"
#include "SysTick.h"
#include "stepper.h"
#include "key.h"
#include "usart.h"
#include "oled.h"
#include "control.h"
#include "trigger.h"
#include "servo.h"
#include <inttypes.h>
#include "mpu6050.h"
#include "bsp_i2c.h"
#include "math.h"

void control(void);
void control1(void);
void shooting(void);
void Get_Angle(void);
extern float g_fAccAngle;
void fire(void);

#endif
