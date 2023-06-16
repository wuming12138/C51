#include <REGX52.H>
#include "Delay.h"
unsigned char MatrixKey()
{
	
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 1;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 5;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 9;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 13;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 2;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 6;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 10;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 14;}

	P1=0xFF;
	P1_1=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 3;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 7;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 11;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 15;}
	
	P1=0xFF;
	P1_0=0;
	if(P1_7==0){Delay(20);while(P1_7==0);Delay(20);return 4;}
	if(P1_6==0){Delay(20);while(P1_6==0);Delay(20);return 8;}
	if(P1_5==0){Delay(20);while(P1_5==0);Delay(20);return 12;}
	if(P1_4==0){Delay(20);while(P1_4==0);Delay(20);return 16;}
}