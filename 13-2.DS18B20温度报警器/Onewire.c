#include <REGX52.H>

sbit DQ=P3^7;

unsigned char Onewire_Init()
{
	unsigned char i, Ackbit;
	EA = 0;
	DQ = 1;
	DQ = 0;
	i = 227;while (--i);		//500us
	DQ = 1;
	i = 29;while (--i);			//70us
	Ackbit  = DQ;
	i = 227;while (--i);		//500us	
	return Ackbit;
	EA = 1;
}

void Onewire_SendBit(unsigned char Bit)
{
	unsigned char i;
	EA = 0;
	DQ = 0;
	i = 4;while (--i);			//10us
	DQ = Bit;
	i = 24;while (--i);			//50us
	DQ = 1;
	EA = 1;
}

unsigned char Onewire_ReceiveBit()
{
	unsigned char Bit, i;
	EA = 0;
	DQ = 0;
	i = 2;while (--i);			//5us
	DQ = 1;
	i = 3;while (--i);			//5us
	Bit = DQ;
	i = 24;while (--i);			//50us
	return Bit;
	EA = 1;
}

void Onewire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		Onewire_SendBit(Byte&(0x01<<i));
	}
}

unsigned char Onewire_ReceiveByte()
{
	unsigned char Byte=0x00, i;
	for(i=0;i<8;i++)
	{
		if(Onewire_ReceiveBit())
			Byte|=(0x01<<i);
	}
	return Byte;
}
