//wap to swap the bits ex:-i/p-0x11223344 o/p:44332211

#include<stdio.h>
void main()
{
	unsigned int x=0x11223344;
	unsigned int y;
	y=((x&0xff000000)>>24)|((x&0x00ff0000)>>8)|((x&0x0000ff00)<<8)|((x&0x000000ff)<<24);
	printf("%x\n",y);
}
