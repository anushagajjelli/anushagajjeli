//wap to check whether a program is little or big endien

#include<stdio.h>
void main()
{
	char x;
	char* ptr;
	char* nptr;
	ptr=&x;
	nptr=&x+3;
	if(nptr==ptr)//comparing variable's address and last address
		printf("BIg\n");
	else
		printf("Little\n");
}
