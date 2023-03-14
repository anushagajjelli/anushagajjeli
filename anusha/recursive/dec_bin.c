//wap for decimal to binary using recursion function

#include<stdio.h>
int decimal_binary(int num,int sum,int i);
main()
{
	int num,sum=0;
	int res;
	int i=1;
	printf("enter the decimal value\n");
	scanf("%d",&num);
	res=decimal_binary(num,sum,i);
	printf("%d",res);
}

int decimal_binary(int num,int sum,int i)
{
	int rem;
	rem=num%2;
	sum=sum+i*rem;
	num=num/2;
	i=i*10;
	if(num>0)
	{
		sum=decimal_binary(num,sum,i);
	}
	return sum;
}
	
	
