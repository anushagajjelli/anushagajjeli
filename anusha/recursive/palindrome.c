//wap for palindrome by using recursive function

#include<stdio.h>
int palindrome(int num,int sum);
main()
{
	int num;
	int sum=0;
	int ret;
	printf("enter the number:");
	scanf("%d",&num);
	printf("main:palindrome(%d)\n",num);
	ret=palindrome(num,sum);
	printf("main: %d\n",ret);
	if(num==ret)
		printf("palindrome\n");
	else
		printf("not a palindrome\n");
}

int palindrome(int num,int sum)
{
	int res,rem,temp;
	//temp=num;
	rem=num%10;
	sum=sum*10+rem;
	num=num/10;
	if(num>0)
	{
		sum=palindrome(num,sum);
	}
	return sum;
	
}
