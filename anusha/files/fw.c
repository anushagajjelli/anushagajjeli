#include<stdio.h>
main()
{
	int x=10;
	{
		x=20;
		int x=40;
		printf("%d\n",x);
	}
	x=50;
	printf("%d\n",x);
}
