//wap to find the sum of the columns and place in other matrix

#include<stdio.h>
#define R 4
#define C 4
void main()
{
	int mat[R][C];
	int res[R][1];
	int i,j,sum=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			//printf("Enter the matrix [%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			sum=sum+mat[j][i];
			//res[R][1]=sum;
		}
		res[i][1]=sum;
		sum=0;
	}
	
	for(i=0;i<R;i++)
	{
		printf("%d\n",res[i][1]);
	}
}		
				
