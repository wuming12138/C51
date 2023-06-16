#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_SendByte(unsigned char WordAddress, Byte);
unsigned char AT24C02_ReadByte(unsigned char WordAddress);

#endif