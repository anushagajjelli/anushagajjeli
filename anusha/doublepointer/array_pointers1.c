//wap for array of pointers using double pointer

#include<stdio.h>
main()
{
	int x[3]={10,20,30};
	int y[3]={40,50,60};
	int *ptr[2]={x,y};
	int i,j;
	printf("%p\n",ptr);//integer variable base address
	printf("%p-%p\n",&ptr[0],ptr[0]);
	printf("%p-%p\n",&ptr[1],ptr[1]);
	for(i=0;i<2;i++)
	{
		printf("%p-%p\t",&ptr[i],ptr[i]);
			for(j=0;j<3;j++)
				printf("%p-%d\n",&ptr[i][j],ptr[i][j]);
	}
}
