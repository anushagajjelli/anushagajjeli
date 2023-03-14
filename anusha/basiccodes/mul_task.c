//wap to perform multiplication of two variables without *..-> operator

#include<stdio.h>
void main()
{
	int a,b,i,sum=0;
	printf("enter the two inputs:");
	scanf("%d %d",&a,&b);
	for(i=0;i<b;i++)
	{
		sum=sum+a;
	}
	printf("%d",sum);
}
		
