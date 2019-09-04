#ifndef _key_H
#define _key_H


#include "system.h"

void KEY_Init(void);
u8 KEY_Scan(u8 mode);  	//按键扫描函数	
 
//#define KEY_LEFT_Pin    GPIO_Pin_2    //定义K_LEFT管脚
//#define KEY_DOWN_Pin    GPIO_Pin_3    //定义K_DOWN管脚
//#define KEY_RIGHT_Pin   GPIO_Pin_4   //定义K_RIGHT管脚
//#define KEY_UP_Pin      GPIO_Pin_0  //定义KEY_UP管脚

//#define KEY_Port (GPIOE) //定义端口
//#define KEY_UP_Port (GPIOA) //定义端口


////使用位操作定义
//#define K_UP PAin(0)
//#define K_DOWN PEin(3)
//#define K_LEFT PEin(2)
//#define K_RIGHT PEin(4)

////使用读取管脚状态库函数定义 
#define K_UP      GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define K_DOWN    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define K_LEFT    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)
#define K_RIGHT   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)
#define K_MIDDLE   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)
#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//读取按键1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键2 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define WKUP_PRES	4		//WK_UP  

////定义各个按键值  
//#define KEY_UP 1
//#define KEY_DOWN 2
//#define KEY_LEFT 3
//#define KEY_RIGHT 4  



#endif
