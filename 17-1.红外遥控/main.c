#include <REGX52.H>
#include "IR.h"
#include "LCD1602.h"

unsigned char Address;
unsigned char Command;
unsigned char Num;

void main()
{
	LCD_Init();
	IR_Init();

	while(1)
	{
		if(IR_GetDateFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			
			LCD_ShowHexNum(2,1,Address,2);
			LCD_ShowHexNum(2,5,Command,2);
			if(Command == 0x15)
			{
				Num--;
			}
			if(Command == 0x09)
			{
				Num++;
			}
			LCD_ShowNum(2,9,Num,3);
		}
	}
}

