#include <REGX52.H>
#include "Delay.h"

sbit SCK = P3^6;
sbit RCK = P3^5;
sbit SER = P3^4;

void _74H595_(unsigned char Byte)
{
	unsigned char i = 0;
	for(i = 0; i < 8; i++)
	{
		SER = Byte&(0x80>>i);	
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}
void MatrixLED_ShowCol(unsigned char col, Date)
{
	_74H595_(Date);
	P0 = ~(0x80>>col);

	Delay(1);
	P0 = 0xFF;
}

void main()
{
	SCK = 0;
	RCK = 0;

	while(1)
	{
		MatrixLED_ShowCol(0,0x80);
		MatrixLED_ShowCol(1,0x40);
		MatrixLED_ShowCol(2,0x20);
		MatrixLED_ShowCol(3,0x10);
	}
}