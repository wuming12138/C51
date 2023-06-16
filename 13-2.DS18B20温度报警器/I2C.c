#include <REGX52.H>

sbit	I2C_SCL = P2^1;
sbit	I2C_SDA = P2^0;

/**
  * @brief  ��ʼ
  * @param  ��
  * @retval ��
  */
void I2C_Start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

/**
  * @brief  ����
  * @param  ��
  * @retval ��
  */
void I2C_Stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

/**
  * @brief  �����ֽ�
  * @param  ���͵��ֽ�
  * @retval ��
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
  * @brief  �����ֽ�
  * @param  ��
  * @retval �ֽ�
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
  * @brief  ����Ӧ��
  * @param  Ӧ��λ
  * @retval ��
  */
void I2C_SendAck(unsigned char Ackbit)
{
	I2C_SDA = Ackbit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

/**
  * @brief  ����Ӧ��
  * @param  ��
  * @retval Ӧ��λ
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