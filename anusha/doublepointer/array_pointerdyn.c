//wap for array of pointers using dynamically requested memory

#include<stdio.h>
#include<stdlib.h>
main()
{
	int ** dptr;
	int i,j;
	dptr=(int**)malloc(2*sizeof(int*));
	if(dptr==NULL)
	{
		printf("failed to allocate memory in heap segment\n:");
		exit(1);
	}
	for(i=0;i<2;i++)
	{
		dptr[i]=(int*)malloc(3*sizeof(int));
		if(dptr==NULL)
		{
		printf("failed to allocate memory in heap segment\n:");
		exit(2);
		}
	}
	read(dptr,2,3);
	display(dptr,2,3);
	for(i=0;i<2;i++)
	{
		free(dptr[i]);
	}
	free(dptr);
}


void read(int ** dptr,int np,int ne)
{
	int i,j;
	for(i=0;i<np;i++)
	{
		for(j=0;j<ne;j++)
		{
			scanf("%d",&dptr[i][j]);
		}
	}
}

void display(int **dptr,int np,int ne)
{
	int i,j;
	for(i=0;i<np;i++)
	{
		printf("%p\n",dptr[i]);
		for(j=0;j<ne;j++)
		{
			printf("%p-%d\n",&dptr[i][j],dptr[i][j]);
		}
		printf("\n");
	}
}
