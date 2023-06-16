#include <REGX52.H>

void Delay(unsigned char x)
{
	while(x--);
}
	
void main()
{
	unsigned char Time, i;
	while(1)
	{
		for(Time=0;Time<100;Time++)
		{
			for(i=0;i<20;i++)
			{
				P2_0=0;
				Delay(Time);
				P2_0=1;
				Delay(100-Time);
			}
		}
		for(Time=0;Time<100;Time++)
		{
			for(i=0;i<20;i++)
			{
				P2_0=1;
				Delay(Time);
				P2_0=0;
				Delay(100-Time);
			}
		}
	}
}