#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"
#include "Delay.h"

unsigned char Count, Compare;
unsigned char Speed;

void main()
{
	unsigned char KeyNum;
	Timer0_Init();

	while(1)
	{
		KeyNum=Key();
		if(KeyNum == 1)
		{
			Speed++;
			Speed%=4;
			if(Speed == 0)Compare = 0;
			if(Speed == 1)Compare = 30;
			if(Speed == 2)Compare = 50;
			if(Speed == 3)Compare = 100;
		}
		Nixie(1,Speed);
	}
}


void Timer0_Routine() interrupt 1
{
	TL0 = 0xA4;
	TH0 = 0xFF;
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