#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"


void main()
{
	unsigned int count = 0;	
	LCD_Init();

	while(1)
	{
		Delay(1000);
		count++;
		LCD_ShowNum(1,1,count,3);
	}
}