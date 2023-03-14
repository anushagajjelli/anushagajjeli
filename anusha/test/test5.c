//wap to perform addition without arithmetic operations

#include<stdio.h>
void add(int a,int b);
main()
{
	int a,b;
	printf("enter the inputs\n");
	scanf("%d %d",&a,&b);
	add(a,b);
}

void add(int a,int b)
{
	int sum;
	sum=a^b;
	printf("%d",sum);
}
