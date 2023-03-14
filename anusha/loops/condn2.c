#include<stdio.h>
main()
{
	int a=6;
	int b=4;
	int c=2;
	int d=8;
	int big;
	big=(((a<b)?b:a)>((c<d)?d:c))?((a<b)?b:a):((c<d)?d:c);
	printf("%d\n",big);
}

