#include<stdio.h>
main()
{
	int a=6;
	int b=4;
	int c=2;
	int d=8;
	int big;
	big=(((a>b)?a:b)>((c>d)?c:d))?((a>b)?a:b):((c>d)?c:d);
	printf("%d\n",big);
}

