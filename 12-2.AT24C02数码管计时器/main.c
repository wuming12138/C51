#include <REGX52.H>
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"
unsigned char KeyNum;
unsigned char min, sec, csec;
unsigned char RunFlag=1;
void main()
{
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum==1)
		{
			RunFlag = !RunFlag;
		}
		if(KeyNum==2)
		{
			min = 0;
			sec = 0;
			csec = 0;
			RunFlag = 0;
 		}
		if(KeyNum==3)
		{
			AT24C02_SendByte(1,min);
			Delay(5);
			AT24C02_SendByte(2,sec);
			Delay(5);
			AT24C02_SendByte(3,csec);
			Delay(5);
	 	}
		if(KeyNum==4)
		{
			min = AT24C02_ReadByte(1);
			sec = AT24C02_ReadByte(2);
			csec = AT24C02_ReadByte(3);
		}
		Nixie_SetBuf(1,min/10);
		Nixie_SetBuf(2,min%10);
		Nixie_SetBuf(3,11);
		Nixie_SetBuf(4,sec/10);
		Nixie_SetBuf(5,sec%10);
		Nixie_SetBuf(6,11);
		Nixie_SetBuf(7,csec/10);
		Nixie_SetBuf(8,csec%10);
	}
}

void Time_Loop()
{
	if(RunFlag == 1)
	{
		csec++;
		if(csec>=100)
		{
			csec=0;
			sec++;
			if(sec>=60)
			{
				sec=0;
				min++;
				if(min>=60)
				{
					min=0;
				}
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1, T0Count2, T0Count3;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0Count1++;
	if(T0Count1>=20)
	{
		T0Count1=0;
		Key_Loop();
	}
	T0Count2++;
	if(T0Count2>=2)
	{
		T0Count2=0;
		Nixie_Loop();
	}
	T0Count3++;
	if(T0Count3>=10)
	{
		T0Count3=0;
		Time_Loop();
	}
}