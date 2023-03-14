#include<stdio.h>
main()
{
	unsigned int x=0xAABBCCDD;
	unsigned int y;
	y=(char)x;
	printf("%d\n",y);
	printf("%c\n",y);
	printf("%x\n",y);
	y=x;
	printf("%x\n",y);
}
