#include "light.h"
#include "systick.h"

void Light_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����ṹ�����	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;	   //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//��������  
	GPIO_Init(GPIOB,&GPIO_InitStructure);		  /* ��ʼ��GPIO */

} 

void charge_fire(int i)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	delay_ms(i);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
}

//void Light_init1(u16 arr,u16 psc)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��ʹ��

//   //���ø�����Ϊ�����������,���TIM3 CH2��PWM���岨��
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //TIM_CH2
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	//GPIO_WriteBit(GPIOA, GPIO_Pin_7,Bit_SET); // PA7����	

//	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
//	
//	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
//	//TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
//	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
//	//TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIMx��CCR2�ϵ�Ԥװ�ؼĴ���
//	
//  //TIM_ARRPreloadConfig(TIM3, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
//	
// 
//	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx����
//}

//void Trigger_Control2()
//{
//	TIM_SetCompare3(TIM3,5); 
//	delay_ms(100);
//	TIM_SetCompare3(TIM3,10); 
//	delay_ms(500);
//	TIM_SetCompare3(TIM3,15); 
//	delay_ms(10);
////	TIM_SetCompare3(TIM3,20); 
////	delay_ms(500);//	
//	TIM_SetCompare3(TIM3,0); 
//	delay_ms(500);
//}

//void Trigger_Control3()
//{
////	TIM_SetCompare3(TIM3,5); 
////	delay_ms(10);
////	TIM_SetCompare3(TIM3,10); 
////	delay_ms(10);
////	TIM_SetCompare3(TIM3,15); 
////	delay_ms(10);
//	TIM_SetCompare3(TIM3,20); 
//	delay_ms(500);//	

//	TIM_SetCompare3(TIM3,15); 
//	delay_ms(100);
//	TIM_SetCompare3(TIM3,10); 
//	delay_ms(10);
//	TIM_SetCompare3(TIM3,0); 
//	delay_ms(500);
//}

