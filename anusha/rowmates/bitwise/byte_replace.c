//wap to replace i/p:11223344 o/p:11553388

#include<stdio.h>
void main()
{
	unsigned int x=0x11223344;
//	x=((x&(~((0x00ff0000)|(0x000000ff))))|(0x00550088));
//	x=((x&(~((0x00ff0000)|(0x000000ff))))|(0x54<<16)|(0x88));
	x=((x&(~((0xff<<16)|(0xff))))|(0x54<<16)|(0x88));
	
	
	printf("%x\n",x);
}
