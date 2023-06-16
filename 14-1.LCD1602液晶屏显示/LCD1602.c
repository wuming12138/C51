#include <REGX52.H>

sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_E=P2^7;

#define LCD_Date P0

void LCD_Delay()		//@11.0592MHz
{
	unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}


void LCD_WriteCommand(unsigned char Byte)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_Date = Byte;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}


void LCD_WriteDate(unsigned char Byte)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_Date = Byte;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}

void Set_Set(unsigned char Line, unsigned char Col)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Col-1));
	}
	else
	{
		LCD_WriteCommand(0x80|(Col-1)+0x40);
	}
}

void LCD_Init()
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}

void LCD_ShowChar(unsigned char Line, unsigned char Col, unsigned char Char)
{
	Set_Set(Line, Col);
	LCD_WriteDate(Char);
}

void LCD_ShowString(unsigned char Line, unsigned char Col, char* String)
{
	Set_Set(Line, Col);
	while(*String)
	{
		LCD_WriteDate(*String);
		String++;
	}
}

int LCD_pow(int x, int y)
{
	unsigned char i;
	int sum = 1;
	for(i=0;i<y;i++)
	{
		sum*=x;
	}
	return sum;
}

void LCD_ShowNum(unsigned char Line, unsigned char Col, unsigned int Num, unsigned char Length)
{
	unsigned char i;
	Set_Set(Line, Col);
	for(i=Length;i>0;i--)
	{
		LCD_WriteDate(0x30|(Num/LCD_pow(10,i-1)%10));

	}

}


void LCD_ShowSignedNum(unsigned char Line, unsigned char Col, int Num, unsigned char Length)
{
	unsigned char i;
	
	Set_Set(Line, Col);
	if(Num<0)
	{
		Num = -Num;
		LCD_WriteDate('-');
	}
	for(i=Length;i>0;i--)
	{
		LCD_WriteDate(0x30|(Num/LCD_pow(10,i-1)%10));

	}
	
}