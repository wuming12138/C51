#include <REGX52.H>
#include "Onewire.h"

void DS18B20_ConvertT()
{
	Onewire_Init();
	Onewire_SendByte(0xCC);
	Onewire_SendByte(0x44);
}

float DS18B20_ReadT()
{
	unsigned char LSB,MSB;
	int Temp;
	float T;
	Onewire_Init();
	Onewire_SendByte(0xCC);
	Onewire_SendByte(0xBE);
	LSB = Onewire_ReceiveByte();
	MSB = Onewire_ReceiveByte();
	Temp = (MSB<<8)|LSB;
	T = Temp / 16.0;
	return T;
}