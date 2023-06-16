#include <REGX52.H>

//�������˿�
sbit Buzzer = P2^5;

unsigned int i = 0;
/**
  * @brief  ��������ʱ����-500ms
  * @param  ��
  * @retval ��
  */
void Buzzer500us()		//@11.0592MHz
{
	unsigned char i;

	i = 227;
	while (--i);
}

/**
  * @brief  ����������
  * @param  ����ʱ��-ms
  * @retval ��
  */
void Buzzer_Time(unsigned int xms)
{
	for(i = 0; i < xms*2; i++)
	{
		Buzzer=!Buzzer;
		Buzzer500us();
	}
}
