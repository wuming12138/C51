#include <REGX52.H>
#include "Timer0_Init.h"
#include "Key.h"
#include <INTRINS.H>
unsigned char KeyNum = 0, LEDmod = 0;
void main()
{
	
	P2=0xFE;
	
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LEDmod++;
				if(LEDmod>1)LEDmod=0;
			}
		}
	}
}

void Timer0()	interrupt 1
{
	static unsigned int T0count = 0,count = 0;
	TH0=64535/256;
	TL0=64535%256+1;
	T0count++;	
	if(T0count >= 500)
	{
		if(LEDmod==0)
		{
//			P2=~(0x01<<count);
//			count++;
//			if(count==8)
//			{
//				count = 0;
//			}
			
			P2=_crol_(P2,1);
		}
			
		if(LEDmod==1)
		{
//			P2=~(0x01<<count);
//			if(count==0)
//			{
//				count = 8;
//			}
//			if(count>0)
//			{
//				count--;
//			}
			
			P2=_cror_(P2,1);
		}
		T0count=0;
	}
}