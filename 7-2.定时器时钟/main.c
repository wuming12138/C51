#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Timer0_Init.h"
unsigned char sec=50, min=59, hour=23;
void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowChar(2,3,':');
	LCD_ShowChar(2,6,':');	
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
	}
}
void Timer0()	interrupt 1
{
	static unsigned int T0count = 0;
	TH0=64535/256;
	TL0=64535%256+1;
	T0count++;
	if(T0count>=1000)
	{
		T0count = 0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=24)
				{
					hour=0;
				}
			}
		}
	}
}	