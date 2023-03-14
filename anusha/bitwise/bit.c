#include<stdio.h>
void main()
{
	unsigned int a=0x123456;
	unsigned int b;
	b=(((a&0xf0000000)>>16)|((a&0x00f00000)>>16)|((a&0x0000f000)<<16)|((a&0x000000f0)<<16)|((a&0x0f000000)>>16)|((a&0x000f0000)>>16)|((a&0x00000f00)<<16)|((a&0x0000000f)<<16));
	printf("%x\n",b);
}
