#include <REGX52.H>
#include "Delay.h"
#include "Timer0_Init.h"

sbit BZ = P2^5;

#define P					0
#define L1				1
#define L1_				2
#define L2				3
#define L2_				4
#define L3				5
#define L4				6
#define L4_				7
#define L5				8
#define L5_				9
#define L6				10
#define L6_				11
#define L7				12
#define M1				13
#define M1_				14
#define M2				15
#define M2_				16
#define M3				17
#define M4				18
#define M4_				19
#define M5				20
#define M5_				21
#define M6				22
#define M6_				23
#define M7				24
#define H1				25
#define H1_				26
#define H2				27
#define H2_				28
#define H3				29
#define H4				30
#define H4_				31
#define H5				32
#define H5_				33
#define H6				34
#define H6_				35
#define H7				36


#define SPEED			500

unsigned int code FraqTable[] = {0,
	63777,63872,63969,64054,64140,64216,64291,64360,64426,64489,64547,64603,
	64655,64704,64751,64795,64837,64876,64913,64948,64981,65012,65042,65070,
	65095,65120,65144,65166,65186,65206,65225,65242,65259,65274,65289,65303
};
unsigned char FraqSel;
unsigned int MusicSel;
unsigned char code Music[] = {
	//??,??,
	
	//1
	P,	4,
	P,	4,
	P,	4,
	M6,	2,
	M7,	2,
	
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	M7,	4+4+4,
	M3,	2,
	M3,	2,
	
	//2
	M6,	4+2,
	M5,	2,
	M6, 4,
	H1,	4,
	
	M5,	4+4+4,
	M3,	4,
	
	M4,	4+2,
	M3,	2,
	M4,	4,
	H1,	4,
	
	//3
	M3,	4+4,
	P,	2,
	H1,	2,
	H1,	2,
	H1,	2,
	
	M7,	4+2,
	M4_,2,
	M4_,4,
	M7,	4,
	
	M7,	8,
	P,	4,
	M6,	2,
	M7,	2,
	
	//4
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	M7,	4+4+4,
	M3,	2,
	M3,	2,
	
	M6,	4+2,
	M5,	2,
	M6, 4,
	H1,	4,
	
	//5
	M5,	4+4+4,
	M2,	2,
	M3,	2,
	
	M4,	4,
	H1,	2,
	M7,	2+2,
	H1,	2+4,
	
	H2,	2,
	H2,	2,
	H3,	2,
	H1,	2+4+4,
	
	//6
	H1,	2,
	M7,	2,
	M6,	2,
	M6,	2,
	M7,	4,
	M5_,4,
	
	
	M6,	4+4+4,
	H1,	2,
	H2,	2,
	
	H3,	4+2,
	H2,	2,
	H3,	4,
	H5,	4,
	
	//7
	H2,	4+4+4,
	M5,	2,
	M5,	2,
	
	H1,	4+2,
	M7,	2,
	H1,	4,
	H3,	4,
	
	H3,	4+4+4+4,
	
	//8
	M6,	2,
	M7,	2,
	H1,	4,
	M7,	4,
	H2,	2,
	H2,	2,
	
	H1,	4+2,
	M5,	2+4+4,
	
	H4,	4,
	H3,	4,
	H3,	4,
	H1,	4,
	
	//9
	H3,	4+4+4,
	H3,	4,
	
	H6,	4+4,
	H5,	4,
	H5,	4,
	
	H3,	2,
	H2,	2,
	H1,	4+4,
	P,	2,
	H1,	2,
	
	//10
	H2,	4,
	H1,	2,
	H2,	2,
	H2,	4,
	H5,	4,
	
	H3,	4+4+4,
	H3,	4,
	
	H6,	4+4,
	H5,	4+4,
	
	//11
	H3,	2,
	H2,	2,
	H1,	4+4,
	P,	2,
	H1,	2,
	
	H2,	4,
	H1,	2,
	H2,	2+4,
	M7,	4,
	
	M6,	4+4+4,
	P,	4,

	0xFF
};
void main()
{
	Timer0_Init();
	while(1)
	{
		if(Music[MusicSel] != 0xFF)
		{
			FraqSel = Music[MusicSel];
			MusicSel++;
			Delay(SPEED/4*Music[MusicSel]);
			MusicSel++;
			TR0 = 0;
			Delay(5);
			TR0 = 1;
		}
		else
		{
			TR0 = 0;
			while(1);
		}
	}
}

void Timer0()	interrupt 1
{
	if(FraqSel)
	{
		TH0 = FraqTable[FraqSel]/256;
		TL0 = FraqTable[FraqSel]%256;
		BZ = !BZ;
	}
}