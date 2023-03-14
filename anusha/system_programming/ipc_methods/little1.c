

#include<stdio.h>
void main()
{
	unsigned int x=0x11223344;
	unsigned char y;
	y=x;
	if(y==(x&(~(~0<<7))))
		printf("Little\n");
	else
		printf("Big\n");
}
	
