#include<stdio.h>
main()
{
int x;
int y;
int big;
printf("enter two inputs x:y\n");
scanf("%d:%d",&x,&y);
big=(x>y)?x:y;
printf("%d\n",big);
}
