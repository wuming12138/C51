#include <REGX52.H>
#include "LCD1602.h"
#include "Key.h"
#include "Delay.h"
#include "AT24C02.h"

unsigned char KeyNum, Num;
void main()
{
	LCD_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				Num++;
			}
			if(KeyNum==2)
			{
				Num--;
			}
			if(KeyNum==3)
			{
				AT24C02_SendByte(0,Num);
				LCD_ShowString(2,1,"OK");
				Delay(1000);
				LCD_ShowString(2,1,"  ");
			}
			if(KeyNum==4)
			{
				Num = AT24C02_ReadByte(0);
			}
		}	
		LCD_ShowNum(1,1,Num,3);
	}
}