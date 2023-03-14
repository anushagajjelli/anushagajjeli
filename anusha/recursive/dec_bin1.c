//wap to print decimal to binary

#include<stdio.h>
int i=1;
int sum=0;
int decimal_binary(int num);
int main()
{
	
	int res;
	int num;
	printf("enter the decimal value\n");
	scanf("%d",&num);
	res=decimal_binary(num);
	printf("%d",res);
}

int decimal_binary(int num)
{
	int rem;
	if(num>0)
	{
		rem=num%2;
		sum=sum+i*rem;
		num=num/2;
		i=i*10;
		decimal_binary(num);
	}
	return sum;
}
	
	
