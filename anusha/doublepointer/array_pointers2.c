//wap of array_pointers using functions including double pointer

#include<stdio.h>
main()
{
	int x[3]={10,20,30};
	int y[3]={40,50,60};
	int *ptr[2]={x,y};
	display(ptr,2,3);
}

void display(int ** dptr,int np,int ne)
{
	int i,j;
	for(i=0;i<np;i++)
	{
		printf("%p-%p\n",&dptr[i],dptr[i]);
		printf("%p-%d\n",&dptr[i],sizeof(&dptr[i]));
		printf("%p-%d\n",dptr[i],sizeof(dptr[i]));
			for(j=0;j<ne;j++)
				printf("%p-%d\n",&dptr[i][j],dptr[i][j]);
		printf("\n");
	}
}
	
