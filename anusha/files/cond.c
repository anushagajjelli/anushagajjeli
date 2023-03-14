#include<stdio.h>
main()
{
int a,b,c,d,e,big;
scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
big=(((a>b)?a:b)>((c>d)?c:d))?((a>b)?a:b):((c>d)?c:((d>e)?d:e));
printf("%d\n",big);
}
