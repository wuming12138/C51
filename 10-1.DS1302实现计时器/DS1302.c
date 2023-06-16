#include <REGX52.H>

sbit DS1302_SCLK = P3^6;
sbit DS1302_CE = P3^5;
sbit DS1302_IO = P3^4;

void DS1302_Init()
{
	DS1302_SCLK = 0;
	DS1302_CE = 0;
}

void DS1302_WriteByte(unsigned char Command, Date)
{
	unsigned char i = 0;
	DS1302_CE = 1;
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Date&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i = 0, Date = 0x00;
	DS1302_CE = 1;
	for(i = 0; i < 8; i++)
	{
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for(i = 0; i < 8; i++)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO){Date |= (0x01<<i);};
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
	return Date;
}

