#include <REGX52.H>
#include "Int0.h"
#include "Timer0.h"

unsigned int IR_Time;
unsigned char IR_State;

unsigned char IR_Date[4];
unsigned char IR_pDate;

unsigned char IR_Address;
unsigned char IR_Command;

unsigned char IR_RepeatFlag;
unsigned char IR_DateFlag;

void IR_Init()
{
	Timer0_Init();
	Int0_Init();
}

unsigned char IR_GetDateFlag()
{
	if(IR_DateFlag)
	{
		IR_DateFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag()
{
	if(IR_RepeatFlag)
	{
		IR_RepeatFlag = 0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress()
{
	return IR_Address;
}

unsigned char IR_GetCommand()
{
	return IR_Command;
}


void Int0_Routine()		interrupt 0
{
	if(IR_State == 0)
	{
		Timer0_SetCounter(0);
		Timer0_Run(1);
		IR_State=1;
		
	}
	else if(IR_State == 1)
	{
		IR_Time = Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time<12440+500 && IR_Time>12400-500)
		{
			IR_State=2;
		}
		else if(IR_Time<10368+500 && IR_Time>10368-500)
		{
			IR_RepeatFlag = 1;
			IR_State = 0;
		}
		else
		{
			IR_State = 1;
		}
	}
	else if(IR_State == 2)
	{
		IR_Time = Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time<1032+300 && IR_Time>1032-300)
		{
			
			IR_Date[IR_pDate/8]&=~(0x01<<IR_pDate%8);
			IR_pDate++;
		}
		else if(IR_Time<2073+500 && IR_Time>2073-500)
		{
			IR_Date[IR_pDate/8]|=0x01<<IR_pDate%8;
			IR_pDate++;
		}
		else
		{
			
			IR_State = 1;
			IR_pDate = 0;
		}
		if(IR_pDate>=32)
		{
			
			IR_pDate = 0;
			if((IR_Date[0]==~IR_Date[1]) && (IR_Date[2]==~IR_Date[3]))
			{
				IR_Address = IR_Date[0];
				IR_Command = IR_Date[2];
				IR_DateFlag = 1;
			}
			Timer0_Run(0);
			IR_State = 0;
		}
	}
}