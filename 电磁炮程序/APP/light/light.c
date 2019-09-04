#include "light.h"
#include "systick.h"

void Light_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //定义结构体变量	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;	   //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//上拉输入  
	GPIO_Init(GPIOB,&GPIO_InitStructure);		  /* 初始化GPIO */

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
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟使能

//   //设置该引脚为复用输出功能,输出TIM3 CH2的PWM脉冲波形
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //TIM_CH2
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);
//	//GPIO_WriteBit(GPIOA, GPIO_Pin_7,Bit_SET); // PA7上拉	

//	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
//	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
//	
//	 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
//	//TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //输出极性:TIM输出比较极性高
//	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
//	//TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR2上的预装载寄存器
//	
//  //TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
//	
// 
//	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
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

