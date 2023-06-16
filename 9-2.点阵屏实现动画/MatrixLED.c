#include <REGX52.H>
#include "Delay.h"

sbit SCK = P3^6;		//SRCLK
sbit RCK = P3^5;		//RCLK
sbit SER = P3^4;		//SER

/**
  * @brief  初始化，需在主函数调用时使用
  * @param  无
  * @retval 无
  */
void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0;
}	

/**
  * @brief  595转码器
  * @param  输入八位编码
  * @retval 无
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
  * @brief  点阵屏输出一列数据
  * @param  列数：0~7
  * @param  高位在上，置1为亮
  * @retval 
  */
void MatrixLED_ShowCol(unsigned char col, Date)
{
	_74H595_(Date);
	P0 = ~(0x80>>col);

	Delay(1);
	P0 = 0xFF;
}
