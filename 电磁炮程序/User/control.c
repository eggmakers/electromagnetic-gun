#include "control.h"

float i=0;
float t=0;
float q=0;
extern u8 control_data[MAX_DATA_LENS];

void goackstraight()
{

	go2(500);
	delay_ms(1);
	stop();
}

void goackback()
{
	back2(500);
	delay_ms(1);
	stop();
}

void gostraight()
{
	go1(500);
	delay_ms(1);
	stop();
}

void goback()
{
	back1(500);
	delay_ms(1);
	stop();
}

void goackstraight1(int z)
{

	go2(500);
	delay_ms(z);
	stop();
}

void goackback1(int z)
{
	back2(500);
	delay_ms(z);
	stop();
}

void gostraight1(int z)
{
	go1(500);
	delay_ms(z);
	stop();
}

void goback1(int z)
{
	back1(500);
	delay_ms(z);
	stop();
}

//void shooting()
//{
//	Trigger();
//}

void control()
{
	u8 key=0;
	q=g_fAccAngle;
	key=KEY_Scan(0);
	if(key==KEY0_PRES)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"2",16);
		OLED_ShowString(16,0,"D:",16);
		OLED_ShowString(70,0,"A:",16);
		OLED_ShowCHinese(0,2,0);
		OLED_ShowCHinese(16,2,1);
		OLED_ShowCHinese(32,2,2);	
		OLED_ShowCHinese(48,2,3);	
		OLED_ShowCHinese(64,2,4);	
	}
	if(key==KEY1_PRES)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"E3",16);
//		OLED_ShowString(16,0,"D:",16);
//		OLED_ShowString(70,0,"A:",16);
		OLED_ShowCHinese(0,2,0);
		OLED_ShowCHinese(16,2,1);
		OLED_ShowCHinese(32,2,5);
		OLED_ShowCHinese(48,2,6);		
		if(control_data[3]==0)
		{
			OLED_ShowString(0,4,"Searching",16);
			goback();
		}
		else if(control_data[3]!=0)
		{
			OLED_ShowString(0,4,"Target Found",16);
			if(control_data[3]<70)
			{
				goback();
			}
			else if(control_data[3]>90)
			{
				gostraight();
			}
			else if(control_data[3]<90&&control_data[3]>70)
			{
				if(control_data[6]>60&&control_data[6]<70)
				{
					goackstraight();
					delay_ms(100);
					shooting();
				}
				else if(control_data[6]>70&&control_data[6]<80)
				{
					goackback();
					delay_ms(100);
					shooting();
				}
				else if(control_data[6]>80&&control_data[6]<90)
				{
					goackback();
					delay_ms(100);
					shooting();
				}
			}
		}
		else if(q>30)
		{
			goackback();
		}
	}
	if(key==WKUP_PRES)
	{
		OLED_Clear();
		OLED_ShowString(0,0,"E4",16);
//		OLED_ShowString(16,0,"D:",16);
//		OLED_ShowString(70,0,"A:",16);
		OLED_ShowCHinese(0,2,0);
		OLED_ShowCHinese(16,2,1);
		OLED_ShowCHinese(32,2,5);
		OLED_ShowCHinese(48,2,6);	
		while(1)
		{
			if(control_data[3]==0)
			{
				OLED_ShowString(0,4,"searching",16);
				goback();
			}
			else if(control_data[3]!=0)
			{
				OLED_ShowString(0,4,"Target Found",16);
				if(control_data[3]<70)
				{
					goback();
				}
				else if(control_data[3]>90)
				{
					gostraight();
				}
				else if(control_data[3]<90&&control_data[3]>70)
				{
					if(control_data[4]>50&&control_data[4]<70)
					{
						shooting();
					}
					if(control_data[4]>70)
					{
						goackback();

					}
					else if(control_data[4]<50)
					{
						goackstraight();

					}
				}
			}
		}
	}		
}

void control1()
{
	if(K_DOWN==0||K_LEFT==0||K_RIGHT==0||K_MIDDLE==0)
	{
		delay_ms(10);  //Ïû¶¶		
		if(K_DOWN==0)
		{	
			i+=0.1;
			if(i>=60) i=0;
			OLED_ShowNum(32,0,i,3,16);
		}
		else if(K_LEFT==0)
		{
			t+=1.8;
			if(t>=60) t=60;
			OLED_ShowNum(32,4,t,3,16);
		}
		else if(K_RIGHT==0)
		{
			t-=1.8;
			if(t<=0) t=0;
			OLED_ShowNum(32,4,t,3,16);
		}
		else if(K_MIDDLE==0)
		{
//			gostraight();
			i-=0.1;
			if(i<=0) i=3;
			OLED_ShowNum(32,0,i,3,16);
		}
	}
	fire();
}

void fire()
{
	if(K_UP==0)
	{
		delay_ms(10);
		if(K_UP==0)
		{
			if(t>30)
			gostraight1(t-30);
			if(t<30)
			goback1(t);
			delay_ms(100);
			goackstraight1(i*0.039);
			delay_ms(100);
			shooting();
		}
	}
}
