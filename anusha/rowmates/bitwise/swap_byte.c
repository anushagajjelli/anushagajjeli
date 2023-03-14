//wap to replace byte i/p:0x12345678 and o/p:0x12775678

#include<stdio.h>
void main()
{
	unsigned int x=0x12345678;
	x=((x&(~(0xff<<16)))|(0x77<<16));
	printf("%x\n",x);
}
