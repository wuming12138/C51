#ifndef __Onewire_H__
#define __Onewire_H__

unsigned char Onewire_Init();
void Onewire_SendBit(unsigned char Bit);
unsigned char Onewire_ReceiveBit();
void Onewire_SendByte(unsigned char Byte);
unsigned char Onewire_ReceiveByte();

#endif