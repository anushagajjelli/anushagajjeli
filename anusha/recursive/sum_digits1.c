//wap to print sumof digits using recursive function

#include<stdio.h>
int sum_digits(int num,int sum);
int main()
{
	int num,res,sum=0;
	printf("enter the number:");
	scanf("%d",&num);
	res=sum_digits(num,sum);
	printf("%d",res);
}

int sum_digits(int num,int sum)
{
	int rem;
	rem=num%10;
	sum=sum+rem;
	num=num/10;
	if(num>0)
	{
		sum=sum_digits(num,sum);
	}
	return sum;
}
	
