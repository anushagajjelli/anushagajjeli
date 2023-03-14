//wap to swap the bits i/p:0x11223344 o/p:22441133

#include<stdio.h>
void main()
{
	unsigned int x=0x11223344;
	x=(((x&(0xff000000))>>16)|((x&(0x00ff0000))<<8)|((x&(0x0000ff00))>>8)|((x&(0x000000ff))<<16));
	printf("%x\n",x);
}
