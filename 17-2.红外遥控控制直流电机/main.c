#include <REGX52.H>
#include "Nixie.h"
#include "Timer1.h"
#include "Delay.h"
#include "IR.h"

unsigned char Count, Compare;
unsigned char Speed;
unsigned char Command;

void main()
{
	unsigned char Num;
	Timer1_Init();
	IR_Init();

	while(1)
	{
		if(IR_GetDateFlag())
		{
			Command = IR_GetCommand();

			if(Command == 0x16){Compare = 0;Speed = 0;}
			if(Command == 0x0C){Compare = 30;Speed = 1;}
			if(Command == 0x18){Compare = 50;Speed = 2;}
			if(Command == 0x5E){Compare = 100;Speed = 3;}
		}
		Nixie(1,Speed);
	}
}


void Timer0_Routine() interrupt 3
{
	TL1 = 0xA4;
	TH1 = 0xFF;
	Count++;
	Count%=100;
	if(Count<Compare)
	{
		P1_0=1;
	}
	else
	{
		P1_0=0;
	}
	
}