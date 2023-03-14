//wap to perform the addtion using bitwise operation

#include<stdio.h>
void main()
{
	int a,b,c;
	printf("Enter the two inputs:");
	scanf("%d %d",&a,&b);
	while(b!=0)
	{
		c=a&b;
		a=a^b;
		b=c<<1;
	}
	printf("sum:%d",a);
}

