#include <REGX52.H>
#include "LCD1602.h"
void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
void main()
{
	LCD_Init();

	LCD_ShowString(1,1,"Hello my world i love you lmh do you like me");

	
	while(1)
	{
		LCD_WriteCommand(0x18);
		Delay500ms();
	}
}