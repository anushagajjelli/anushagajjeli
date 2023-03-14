//wap to perform the swap operation in bitwise using i/p:AA224466 o/p:55228866

#include<stdio.h>
void main()
{
	unsigned int x=0xAA224466;
	unsigned int y=0x5588;//0x00005588 to change the bytes in place of A and 44
	unsigned int z;
	z=((y<<16)&(0xFF000000))|(x&(0x00FF0000))|((y<<8)&(0x0000FF00))|(x&(0x000000FF));
	printf("0x%x\n",z);
}

