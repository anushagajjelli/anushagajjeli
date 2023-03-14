//wap to print sumof digits using recursive function

#include<stdio.h>
int sum=0;
int sum_digits(int num);
int main()
{
	int num,res;
	printf("enter the number:");
	scanf("%d",&num);
	res=sum_digits(num);
	printf("%d",res);
}

int sum_digits(int num)
{
	int rem;
	rem=num%10;
	sum=sum+rem;
	num=num/10;
	if(num>0)
	{
		sum_digits(num);
	}
	return sum;
}
	
