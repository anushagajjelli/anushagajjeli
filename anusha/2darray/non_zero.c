//wap to print non zero values in matrix

#include<stdio.h>
#define R 4
#define C 4
void main()
{
	int mat[R][C];
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			//printf("Enter the matrix [%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Before change of matrix\n");
	for(i=0;i<R;i++,printf("\n"))
	{
		for(j=0;j<C;j++)
		{
			printf("%d",mat[i][j]);
			//scanf("%d",&mat[i][j]);
		}
	}
	printf("After the change of matrix\n");
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(mat[i][j]!=0)
			{
				printf("Row and column[%d][%d]:%d\n",i,j,mat[i][j]);
			}
		}
	}
}
