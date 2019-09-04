#include "stepper.h"

void DIR_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义结构体变量
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;  //选择你要设置的IO口    GPIO_Pin_3|
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */	
}

static void TIM2_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	/* TIM2 clock enable */
	//PCLK1经过2倍频后作为TIM2的时钟源等于72MHz
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 

  /* GPIOA and GPIOB clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 

  /*GPIOA Configuration: TIM2 channel 1 and 2 as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    // 复用推挽输出GPIO_Pin_1|
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);

}

/*
 * 函数名：TIM2_Mode_Config
 * 描述  ：配置TIM2输出的PWM信号的模式，如周期、极性、占空比
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用
 */
static void TIM2_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	/* PWM信号电平跳变值 */
	u16 CCR1_Val =  0;        
	u16 CCR3_Val =  0;

  /* Time base configuration */		 
  TIM_TimeBaseStructure.TIM_Period = 999;       //当定时器从0计数到999，即为1000次，为一个定时周期
  TIM_TimeBaseStructure.TIM_Prescaler = 71;	    //设置预分频：不预分频，即为72MHz
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//设置时钟分频系数：不分频
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_Pulse =CCR1_Val  ;	   //设置跳变值，当计数器计数到这个值时，电平发生跳变
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR1_Val时为高电平

  TIM_OC2Init(TIM2, &TIM_OCInitStructure);	 //使能通道1

  TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel2 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = CCR3_Val;	  //设置通道2的电平跳变值，输出另外一个占空比的PWM

  TIM_OC3Init(TIM2, &TIM_OCInitStructure);	  //使能通道2

  TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);

  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);                   //使能定时器3	
}

/*
 * 函数名：TIM2_PWM_Init
 * 描述  ：TIM2 输出PWM信号初始化，只要调用这个函数
 *         TIM2的四个通道就会有PWM信号输出
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 */
void Stepper_Init(void)
{
	TIM2_GPIO_Config();
	TIM2_Mode_Config();	
	DIR_Init();
}

void go1(u16 pwm1)
{
	DIR1_ON;
	TIM_SetCompare2(TIM2,pwm1);
	TIM_SetCompare3(TIM2,0);
}

void back1(u16 pwm2)
{
	DIR1_OFF;
	TIM_SetCompare2(TIM2,pwm2);
	TIM_SetCompare3(TIM2,0);
}

void go2(u16 pwm3)
{
	DIR2_ON;
	TIM_SetCompare3(TIM2,pwm3);
	TIM_SetCompare2(TIM2,0);
}

void back2(u16 pwm4)
{
	DIR2_OFF;
	TIM_SetCompare3(TIM2,pwm4);
	TIM_SetCompare2(TIM2,0);
}

void stop()
{
	TIM_SetCompare3(TIM2,0);
	TIM_SetCompare2(TIM2,0);
}
