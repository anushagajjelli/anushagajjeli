#include<stdio.h>
#include<stdlib.h>
#include"header.h"
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






