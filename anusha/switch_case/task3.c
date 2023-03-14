/*wap to perform bitwise ,mathematical operations,swapping variables,characters and fibonacci series in switchcases using the functions*/

#include<stdio.h>
int reverse_integer (int);
int binary_decimal(int);
int reverse_integer(int num)
{
	int temp=num,rem,sum=0;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum*10+rem;
	}
	return sum;
}
int binary_decimal(int bin)
{
	int temp=bin,rem,dec=0,i=1;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem>1)
			return -1;
		dec=dec+i*rem;
		i=i*2;
		temp=temp/10;
	}
	return dec;
}


void main(void)
{
	int num,opt,i,bin,res;
	while(1)
	{
		printf("MENU\n\t0.exit\n1.reverse_int\n2.binary_decimal\n");
		printf("select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
		case 0:exit(0);

		case 1:printf("enter the number\n");
			scanf("%d",&num);
			res=reverse_integer(num);
			printf("%d\n",res);
			break;

		case 2:printf("enter the binary input\n");
			scanf("%d",&bin);
			res=binary_decimal(bin);
			if(res==-1)
			{
				printf("invalid input\n");
					break;
			}
			printf("%d",res);
				break;
		default:printf("invalid option\n");

		}
	}	
}












