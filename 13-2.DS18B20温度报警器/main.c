#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B02.h"
#include "Key.h"
#include "AT24C02.h"
#include "Delay.h"
#include "Timer0_Init.h"

sbit BZ = P2^5;

float T;
unsigned char KeyNum;
unsigned char THigh,TLow;


void main()
{
//	Timer0_Init();
	LCD_Init();
	LCD_ShowString(2,1,"H:");
	LCD_ShowString(2,8,"L:");
	THigh = AT24C02_ReadByte(1);
	TLow = AT24C02_ReadByte(2);
	
	while(1)
	{
		KeyNum = Key();
		
		DS18B20_ConvertT();
		T = DS18B20_ReadT();
		if(T<0)
		{
			LCD_ShowChar(1,1,'-');
			T = -T;
		}
		else
		{
			LCD_ShowChar(1,1,'+');
		}
		LCD_ShowNum(1,2,T,3);
		LCD_ShowChar(1,5,'.');
		LCD_ShowNum(1,6,(unsigned long)(T*10)%10,1);
		
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				THigh++;
				if(THigh>99)THigh = 99;
			}
			if(KeyNum == 2)
			{
				THigh--;
				if(THigh<=TLow)THigh++;
				if(THigh>200)THigh=0;
			}
			if(KeyNum == 3)
			{
				TLow++;
				if(THigh<=TLow)TLow--;
			}
			if(KeyNum == 4)
			{
				TLow--;
				if(TLow>200)TLow = 0;
			}				
		}
		LCD_ShowNum(2,3,THigh,2);
		LCD_ShowNum(2,10,TLow,2);
		AT24C02_SendByte(1,THigh);
		Delay(5);
		AT24C02_SendByte(2,TLow);
		Delay(5);
		
		if(T>THigh)
		{
			LCD_ShowString(1,13,"OV:H");
		}
		else if(T<TLow)
		{
			LCD_ShowString(1,13,"OV:L");
		}
		else
		{
			LCD_ShowString(1,13,"    ");
		}
	}
}


//void Timer0()	interrupt 1
//{

//	TH0=0;
//	TL0=0;
//	BZ = !BZ;
//}