//wap to perform the ascending operation in matrix

#include<stdio.h>
#define R 4
#define C 4
void mat_ascending(int (*mat)[4]);
void main()
{
	int i,j;
	int mat[R][C];
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("Enter the matrix [%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	mat_ascending(mat);
}


void mat_ascending(int (*mat)[4])
{
	int i,j,m=0,temp;
	for(i=0;i<R;i++)
	{
		for(m=0;m<R;m++)
		{
			for(j=m+1;j<C;j++)
			{
				if(mat[i][m]>mat[i][j])
				{
					temp=mat[i][m];
					mat[i][m]=mat[i][j];
					mat[i][j]=temp;
				}
			}
		}	
		//printf("%d\t",mat[i][j]);
	}
	
	

	for(i=0;i<R;i++,printf("\n"))
	{
		for(j=0;j<C;j++)
		{
			printf("%d\t",mat[i][j]);
			
		}
	}
}
