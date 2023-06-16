#include <REGX52.H>

void Timer0_Init()
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TR0=1;
	TF0=0;
	TL0 = 0x66;		
	TH0 = 0xFC;		
	EA=1;
	ET0=1;
	PT0=0;
}

/*
void Timer0()	interrupt 1
{
	static unsigned int T0count = 0;
	TL0 = 0x66;		
	TH0 = 0xFC;	
	T0count++;
	if(T0count >= 1000)
	{	
		T0count = 0;

	}
}	
*/