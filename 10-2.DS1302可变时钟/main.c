#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "Timer0_Init.h"
#include "Key.h"
unsigned char KeyNum, MODE, Timesel, FlashFlag; 

void timeshow()
{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_Time[0],2);
		LCD_ShowNum(1,4,DS1302_Time[1],2);
		LCD_ShowNum(1,7,DS1302_Time[2],2);
		LCD_ShowNum(2,1,DS1302_Time[3],2);
		LCD_ShowNum(2,4,DS1302_Time[4],2);
		LCD_ShowNum(2,7,DS1302_Time[5],2);
}
void timeset()
{
	if(KeyNum == 2)
	{
		Timesel++;
		Timesel %= 6;
	}
	if(KeyNum == 3)
	{
		DS1302_Time[Timesel]++;
	}
	if(KeyNum == 4)
	{
		DS1302_Time[Timesel]--;
	}
	if(Timesel==0 && FlashFlag == 1){LCD_ShowString(1,1,"  ");}
	else{LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(Timesel==1 && FlashFlag == 1){LCD_ShowString(1,4,"  ");}
	else{LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(Timesel==2 && FlashFlag == 1){LCD_ShowString(1,7,"  ");}
	else{LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(Timesel==3 && FlashFlag == 1){LCD_ShowString(2,1,"  ");}
	else{LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(Timesel==4 && FlashFlag == 1){LCD_ShowString(2,4,"  ");}
	else{LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(Timesel==5 && FlashFlag == 1){LCD_ShowString(2,7,"  ");}
	else{LCD_ShowNum(2,7,DS1302_Time[5],2);}	
}
void main()
{
	DS1302_Init();
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_SetTime();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
				if(MODE == 0){MODE = 1;}
				else if(MODE == 1){MODE = 0;DS1302_SetTime();Timesel = 0;};
		}
		switch(MODE)
		{
			case 0:

				timeshow();
				break;
			case 1:

				timeset();
				break;
		}
	}
}

void Timer0()	interrupt 1
{
	static unsigned int T0count = 0;
	TL0 = 0x66;		
	TH0 = 0xFC;	
	T0count++;
	if(T0count >= 500)
	{	
		T0count = 0;
		FlashFlag = !FlashFlag;
	}
}	
