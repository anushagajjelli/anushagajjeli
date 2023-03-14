#include<stdio.h>

void main(int argv,char *argc[],char *env[])
{
	int i;
	for(i=0;i<30;i++)
		printf("%d\t%s\n",i,env[i]);
}
