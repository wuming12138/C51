#include <REGX52.H>


void UART_Init()	//4800bps@11.0592MHz
{
	SCON = 0x50;
	PCON |= 0;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xFA;
	TH1 = 0xFA;
	ET1 = 0;
	TR1 = 1;
}
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI == 0;
}
