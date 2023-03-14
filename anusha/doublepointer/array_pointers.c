//wap of array of pointers

#include<stdio.h>
main()
{
	int *ptr[4];//array pointer which access address
	
	int i;
	int x=10;
	int y=20;
	int z=30;
	int v=40;
	ptr[0]=&v;
	ptr[1]=&z;
	ptr[2]=&y;
	ptr[3]=&x;
	for(i=0;i<5;i++)
	{
		printf("%p\n",ptr[i]);
		printf("%d\n",*ptr[i]);
		printf("%p-%p-%d\n",&ptr[i],ptr[i],*ptr[i]);
	}
}
