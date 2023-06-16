#include <REGX52.H>

sbit	I2C_SCL = P2^1;
sbit	I2C_SDA = P2^0;

/**
  * @brief  开始
  * @param  无
  * @retval 无
  */
void I2C_Start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

/**
  * @brief  结束
  * @param  无
  * @retval 无
  */
void I2C_Stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

/**
  * @brief  发送字节
  * @param  发送的字节
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i = 0;
	for(i=0;i<8;i++)
	{
		I2C_SDA = Byte&(0x80>>i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
}

/**
  * @brief  接收字节
  * @param  无
  * @retval 字节
  */
unsigned char I2C_ReceiveByte()
{
	unsigned char Byte = 0x00, i = 0;
	I2C_SDA = 1;
	
	for(i=0;i<8;i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA){Byte|=0x80>>i;}
		I2C_SCL = 0;
	}

	return Byte;
}

/**
  * @brief  发送应答
  * @param  应答位
  * @retval 无
  */
void I2C_SendAck(unsigned char Ackbit)
{
	I2C_SDA = Ackbit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

/**
  * @brief  接收应答
  * @param  无
  * @retval 应答位
  */
unsigned char I2C_ReceiveAck()
{
	unsigned char Ackbit = 0;
	I2C_SDA = 1;
	I2C_SCL = 1;
	Ackbit = I2C_SDA;
	I2C_SCL = 0;
	return Ackbit;
}