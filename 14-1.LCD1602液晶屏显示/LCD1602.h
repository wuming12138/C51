#ifndef __LCD1602_H__
#define __LCD1602_H__

void LCD_Init();
void LCD_ShowChar(unsigned char Line, unsigned char Col, unsigned char Char);
void LCD_ShowString(unsigned char Line, unsigned char Col, char* String);
void LCD_ShowNum(unsigned char Line, unsigned char Col, unsigned int Num, unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line, unsigned char Col, int Num, unsigned char Length);
void LCD_WriteCommand(unsigned char Byte);	

#endif