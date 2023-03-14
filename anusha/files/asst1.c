#include<stdio.h>
int sum_digits(int);
main()
{
	int num=823;
	int temp=num,rem=0,sum=0,res=0;
	printf("main:%p:num-%p-%d\n",main,&num,num);
	printf("main:%p:sum-%p-%d\n",main,&sum,sum);
	printf("main:%p:res-%p-%d\n",main,&res,res);
	printf("main:%p:temp-%p-%d\n",main,&temp,temp);
	printf("main:%p:rem-%p-%d\n",main,&rem,rem);
	printf("main:calling sum_digits\n");
	res=sum_digits(num);
	printf("main:%p:res-%p-%d\n",main,&res,res);
}
int sum_digits(int num)
{
	int temp=num,rem,sum=0;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum+rem;
	}
	//printf("sum_digits:%p:num-%p-%d\n",sum_digits,&num,num);
	printf("main:%p:num-%p-%d\n",main,&num,num);
	return sum;
}

