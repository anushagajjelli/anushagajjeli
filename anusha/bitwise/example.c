#include<stdio.h>
void main()
{
	unsigned int x=0x41424344;
	unsigned char *ptr;
	ptr=&x;
	*ptr=0xaabbccdd;
	printf("%p-%d-%c\n",ptr,*ptr,*ptr);
}
