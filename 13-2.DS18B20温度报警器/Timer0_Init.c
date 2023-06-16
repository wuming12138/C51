#include <REGX52.H>

void Timer0_Init()
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TR0=1;
	TF0=0;
	TH0=64535/256;
	TL0=64535%256+1;
	EA=1;
	ET0=1;
	PT0=0;
}

/*
void Timer0()	interrupt 1
{
	static unsigned int T0count = 0;
	TH0=64535/256;
	TL0=64535%256+1;
	T0count++;
	if(T0count >= 1000)
	{	
		T0count = 0;

	}
}
*/