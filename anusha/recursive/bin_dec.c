//wap for binary to decimal using recursion function

#include<stdio.h>
int binary_decimal(int num,int sum,int i);
main()
{
	int num,sum=0;
	int res;
	int i=1;
	printf("enter the decimal value\n");
	scanf("%d",&num);
	res=binary_decimal(num,sum,i);
	printf("%d",res);
}

int binary_decimal(int num,int sum,int i)
{
	int rem;
	rem=num%10;
	sum=sum+i*rem;
	num=num/10;
	i=i*2;
	if(num>0)
	{
		sum=binary_decimal(num,sum,i);
	}
	return sum;
}

