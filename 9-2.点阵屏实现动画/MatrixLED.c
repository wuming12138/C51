#include <REGX52.H>
#include "Delay.h"

sbit SCK = P3^6;		//SRCLK
sbit RCK = P3^5;		//RCLK
sbit SER = P3^4;		//SER

/**
  * @brief  ��ʼ������������������ʱʹ��
  * @param  ��
  * @retval ��
  */
void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0;
}	

/**
  * @brief  595ת����
  * @param  �����λ����
  * @retval ��
  */
void _74H595_(unsigned char Byte)
{
	unsigned char i = 0;
	for(i = 0; i < 8; i++)
	{
		SER = Byte&(0x80>>i);	
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief  ���������һ������
  * @param  ������0~7
  * @param  ��λ���ϣ���1Ϊ��
  * @retval 
  */
void MatrixLED_ShowCol(unsigned char col, Date)
{
	_74H595_(Date);
	P0 = ~(0x80>>col);

	Delay(1);
	P0 = 0xFF;
}
