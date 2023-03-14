#include<stdio.h>

int add(int a,int b)
{
	int c;
	c=a+b;
	return c;
}

void main()
{
	int a=10,b=20,c;
	c=add(a,b);
	printf("%d\n",c);
}

