//wap to print the even or odd number using bitwise

#include<stdio.h>
void main()
{
	int x;
	printf("Enter the number:");
	scanf("%d",&x);
	if((x&(0x1))==0)
		printf("even");
	else
		printf("odd");
}
