//wap for binary to decimal using recursion function

#include<stdio.h>
int sum=0;
int i=1;
int binary_decimal(int num);
int main()
{
	int num;
	int res;
	printf("enter the binary value\n");
	scanf("%d",&num);
	res=binary_decimal(num);
	printf("%d",res);
}

int binary_decimal(int num)
{
	int rem;
	rem=num%10;
	sum=sum+i*rem;
	num=num/10;
	i=i*2;
	if(num>0)
	{
		printf("%d\n",sum);
		binary_decimal(num);
		//printf("%d\n",num);
	}
	return sum;
}

