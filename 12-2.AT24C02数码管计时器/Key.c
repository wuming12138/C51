#include <REGX52.H>
#include "Delay.h"

unsigned char Key_Key;
	
unsigned char Key()
{
	unsigned char tmp = Key_Key;
	Key_Key=0;
	return tmp;
}

unsigned char KeyState()
{
	unsigned char KeyNumber = 0;
	if(P3_1==0){KeyNumber = 1;}
	if(P3_0==0){KeyNumber = 2;}
	if(P3_2==0){KeyNumber = 3;}
	if(P3_3==0){KeyNumber = 4;}
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char NowState,LastState;
	LastState = NowState;
	NowState = KeyState();
	if(NowState == 0 && LastState == 1)
	{
		Key_Key = 1;
	}
	if(NowState == 0 && LastState == 2)
	{
		Key_Key = 2;
	}
	if(NowState == 0 && LastState == 3)
	{
		Key_Key = 3;
	}
	if(NowState == 0 && LastState == 4)
	{
		Key_Key = 4;
	}
}
