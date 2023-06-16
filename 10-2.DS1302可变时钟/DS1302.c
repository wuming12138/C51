#include <REGX52.H>

sbit DS1302_SCLK = P3^6;
sbit DS1302_CE = P3^5;
sbit DS1302_IO = P3^4;

#define DS1302_SEC			0x80
#define DS1302_MIN			0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH		0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP				0x8E

unsigned char DS1302_Time[] = {22, 12, 29, 1, 3, 25, 4};	//年 月 日 小时 分钟 秒 星期

/**
  * @brief  初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_SCLK = 0;
	DS1302_CE = 0;
}

/**
  * @brief  写入字节
  * @param  地址
  * @param  写入数据
  * @retval 无
  */
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

/**
  * @brief  读出数据
  * @param  地址
  * @retval 数据
  */
unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i = 0, Date = 0x00;
	Command |= 0x01;
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

/**
  * @brief  写入DS1302_Time内的数据
  * @param  无
  * @retval 无
  */
void DS1302_SetTime()
{
	DS1302_WriteByte(DS1302_WP, 0x00);		//关闭写入保护
	DS1302_WriteByte(DS1302_YEAR, DS1302_Time[0]/10*16 + DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH, DS1302_Time[1]/10*16 + DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE, DS1302_Time[2]/10*16 + DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR, DS1302_Time[3]/10*16 + DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MIN, DS1302_Time[4]/10*16 + DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SEC, DS1302_Time[5]/10*16 + DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY, DS1302_Time[6]/10*16 + DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP, 0x80);		//
}

/**
  * @brief  把时钟信息再返回DS1302_Time
  * @param  无
  * @retval 无
  */
void DS1302_ReadTime()
{
	unsigned char temp = 0;
	temp = DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_MIN);
	DS1302_Time[4] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_SEC);
	DS1302_Time[5] = temp/16*10 + temp%16;
	temp = DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6] = temp/16*10 + temp%16;
}