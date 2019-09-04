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
#include "light.h"

short x_nAcc,y_nAcc,z_nAcc;//加速度x轴，y轴，z轴数据
short x_nGyro,y_nGyro,z_nGyro;
float x_fAcc,y_fAcc,z_fAcc;

float g_fAccAngle;
float g_fGyroAngleSpeed;
float g_fCarAngle;
float s_dt=0.005;

float angle;
float a;

float ComplementaryFilter(float acc,float gyro,float dt)
{
	a=0.98;
	angle=a*(angle+gyro*dt)+(1-a)*(acc);
	return angle;
}

int main()
{
	short Accel[3];
	short Gyro[3];
	SysTick_Init (72);
	Stepper_Init();
	KEY_Init();
	uart_init(115200);  
	OLED_Init();
//	Trigger_Init();
	Servo_Init(199,7199);
	i2c_GPIO_Config();
	OLED_Clear();
	MPU6050_Init();
	Light_Init();
//	TIM_SetCompare2(TIM3,0); 
	//电磁炮测试
	OLED_ShowCHinese(16,0,7);
	OLED_ShowCHinese(32,0,8);
	OLED_ShowCHinese(48,0,9);
	OLED_ShowCHinese(64,0,10);
	OLED_ShowCHinese(80,0,11);
	OLED_ShowString(6,2,"UP 4 K0 2 K1 3",16);
	if (MPU6050ReadID() == 1)
	{	
		while(1)
		{
			control();
			control1();
			MPU6050ReadAcc(Accel);
			MPU6050ReadGyro(Gyro);
			x_fAcc=Accel[0]/16384.0;
			y_fAcc=Accel[1]/16384.0;
			z_fAcc=Accel[2]/16384.0;
			
			g_fAccAngle=atan2(y_fAcc,z_fAcc)/3.14*180.0;
			g_fGyroAngleSpeed=x_nGyro/16.4;
			g_fCarAngle=ComplementaryFilter(g_fAccAngle,g_fGyroAngleSpeed,s_dt);
			OLED_ShowNum(70,0,(u32)g_fCarAngle,7,16);
//		     TIM_SetCompare2(TIM3,5); 
//         delay_ms(500);
//         TIM_SetCompare2(TIM3,10); 
//         delay_ms(500);
//         TIM_SetCompare2(TIM3,15); 
//         delay_ms(500);
//         TIM_SetCompare2(TIM3,20); 
//         delay_ms(500);//	
//		 
//         TIM_SetCompare2(TIM3,15); 
//         delay_ms(500);
//				TIM_SetCompare2(TIM3,10); 
//         delay_ms(500);
		}
	}
}


