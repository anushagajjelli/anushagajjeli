//wap for factorial by using recursive function

#include<stdio.h>
main()
{
	int num=4;
	int fact;
	printf("main:fact(%d)\n",num);
	fact=factorial(num);
	printf("main: %d\n",fact);
}

int factorial(int num)
{
	int res;
	printf("fatorial(%d)\n",num);
	if(num==0)
		return 1;
	res=num*factorial(num-1);
	printf("factorial(%d)->return values %d\n",num,res);
	return res;
}
