#ifndef _key_H
#define _key_H


#include "system.h"

void KEY_Init(void);
u8 KEY_Scan(u8 mode);  	//����ɨ�躯��	
 
//#define KEY_LEFT_Pin    GPIO_Pin_2    //����K_LEFT�ܽ�
//#define KEY_DOWN_Pin    GPIO_Pin_3    //����K_DOWN�ܽ�
//#define KEY_RIGHT_Pin   GPIO_Pin_4   //����K_RIGHT�ܽ�
//#define KEY_UP_Pin      GPIO_Pin_0  //����KEY_UP�ܽ�

//#define KEY_Port (GPIOE) //����˿�
//#define KEY_UP_Port (GPIOA) //����˿�


////ʹ��λ��������
//#define K_UP PAin(0)
//#define K_DOWN PEin(3)
//#define K_LEFT PEin(2)
//#define K_RIGHT PEin(4)

////ʹ�ö�ȡ�ܽ�״̬�⺯������ 
#define K_UP      GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define K_DOWN    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define K_LEFT    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)
#define K_RIGHT   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)
#define K_MIDDLE   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)
#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)//��ȡ����0
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//��ȡ����1
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����2 

#define KEY0_PRES	1		//KEY0  
#define KEY1_PRES	2		//KEY1 
#define WKUP_PRES	4		//WK_UP  

////�����������ֵ  
//#define KEY_UP 1
//#define KEY_DOWN 2
//#define KEY_LEFT 3
//#define KEY_RIGHT 4  



#endif
