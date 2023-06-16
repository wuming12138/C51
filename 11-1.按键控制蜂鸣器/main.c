#include <REGX52.H>
#include "fun.h"
#include "Key.h"
#include "Buzzer.h"
	
unsigned char KeyNum = 0;
void main()
{
	Nixie(1, 0);
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			Buzzer_Time(1000);
			Nixie(1, KeyNum);
		}
	}
}