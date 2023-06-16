#include <REGX52.H>

//蜂鸣器端口
sbit Buzzer = P2^5;

unsigned int i = 0;
/**
  * @brief  蜂鸣器延时函数-500ms
  * @param  无
  * @retval 无
  */
void Buzzer500us()		//@11.0592MHz
{
	unsigned char i;

	i = 227;
	while (--i);
}

/**
  * @brief  蜂鸣器发声
  * @param  发声时间-ms
  * @retval 无
  */
void Buzzer_Time(unsigned int xms)
{
	for(i = 0; i < xms*2; i++)
	{
		Buzzer=!Buzzer;
		Buzzer500us();
	}
}
