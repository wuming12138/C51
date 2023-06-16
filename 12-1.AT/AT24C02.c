#include <REGX52.H>
#include "I2C.h"

/**
  * @brief  写入一个字节
  * @param  写入地址
	* @param  写入数据
  * @retval 无
	写完后应该延迟5ms!!!!!!!!!!
  */
void AT24C02_SendByte(unsigned char WordAddress, Byte)
{
	I2C_Start();
	I2C_SendByte(0xA0);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Byte);
	I2C_ReceiveAck();	
	I2C_Stop();
}

/**
  * @brief  读取一个字节
  * @param  
  * @retval 
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Byte;
	I2C_Start();
	I2C_SendByte(0xA0);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	
	I2C_Start();
	I2C_SendByte(0xA1);
	I2C_ReceiveAck();
	Byte = I2C_ReceiveByte();
	I2C_SendAck(1);
	
	I2C_Stop();
	return Byte;
}