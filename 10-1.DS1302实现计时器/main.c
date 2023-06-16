#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
unsigned char sec = 0, min = 0, hour, mod_CH = 0, mod_start = 1;
void main()
{

	DS1302_Init();
	LCD_Init();
	DS1302_WriteByte(0X8E, 0x00);
	DS1302_WriteByte(0x80, 0x00);	//sec
	DS1302_WriteByte(0x82, 0x00);	//min
	DS1302_WriteByte(0x84, 0x00);	//hour
	LCD_ShowChar(2,3,':');
	LCD_ShowChar(2,6,':');
	while(1)
	{
		//ģʽ0�¿�ʼ��ʱ��ģʽ1������
		if(mod_start == 0)
		{
			sec = DS1302_ReadByte(0x81)%16 + ((DS1302_ReadByte(0x81)/16)%8)*10;
			min = DS1302_ReadByte(0x83)%16 + (DS1302_ReadByte(0x83)/16)*10;
			hour = DS1302_ReadByte(0x85)%16 + (DS1302_ReadByte(0x85)/16)*10;
			LCD_ShowNum(2,7,sec,2);
			LCD_ShowNum(2,4,min,2);
			LCD_ShowNum(2,1,hour,2);
		}
		else
		{
			DS1302_WriteByte(0x80, 0x00);	//sec
			DS1302_WriteByte(0x82, 0x00);	//min
			DS1302_WriteByte(0x84, 0x00);	//hour
			LCD_ShowNum(2,7,0,2);
			LCD_ShowNum(2,4,0,2);
			LCD_ShowNum(2,1,0,2);
		}
		
		//���µڶ�������ͣ
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			if(mod_CH == 0)		//mod_CHΪ0ʱ��ͣ
			{
				DS1302_WriteByte(0x80, DS1302_ReadByte(0x81) | 0x80);
				mod_CH = 1;
			}
			else							//mod_CHΪ1ʱ��ʼ
			{
				DS1302_WriteByte(0x80, DS1302_ReadByte(0x81) & 0x7F);
				mod_CH = 0;
			}
		}

		
		//���µ�һ������ģʽ�л���0��1ѭ��
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			mod_start++;
			if(mod_start >= 2)
			{
				mod_start = 0;
			}
		}
	}
}
