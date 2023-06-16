#include <REGX52.H>
#include "I2C.h"

/**
  * @brief  д��һ���ֽ�
  * @param  д���ַ
	* @param  д������
  * @retval ��
	д���Ӧ���ӳ�5ms!!!!!!!!!!
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
  * @brief  ��ȡһ���ֽ�
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