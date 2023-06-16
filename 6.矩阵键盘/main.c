#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

void main()
{
	unsigned char KeyNum = 0,times = 0;
	unsigned int PutNum = 0;
	unsigned int RightNum = 2345;
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	LCD_ShowString(2,1,"****");
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum && KeyNum<=10 && PutNum<1000)
		{
			PutNum *= 10;
			PutNum += KeyNum%10;
			LCD_ShowNum(2,1,PutNum,4);
		}
		if(KeyNum==12)
		{
			PutNum = 0;
			LCD_ShowNum(2,1,PutNum,4);
		}
		if(KeyNum==11)
		{
			if(PutNum==RightNum)
			{
				LCD_ShowString(2,1,"****");
				PutNum = 0;
				for(times=3;times>0;times--)
				{
					LCD_ShowString(1,12,"OK   ");
					Delay(500);
					LCD_ShowString(1,12,"     ");
					Delay(500);
				}
			}
			else
			{
				LCD_ShowString(2,1,"****");
				PutNum = 0;
				for(times=3;times>0;times--)
				{
					LCD_ShowString(1,12,"ERROR");
					Delay(500);
					LCD_ShowString(1,12,"     ");
					Delay(500);
				}
			}
		}
	}
}