//wap to print non zero values in matrix

#include<stdio.h>
#define R 4
#define C 4
void main()
{
	int mat[R][C];
	int i,j,count=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(mat[i][j]!=0)
			{
				count++;
			}
		}
	}
	int arr[count][3],k=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			int l=0;
			if(mat[i][j]!=0)
			{
					arr[k][l]=i;
					l++;
					arr[k][l]=j;
					l++;
					arr[k][l]=mat[i][j];
					k++;
			}
		}
	}
	printf("Positive values and their index\n");
	for(i=0;i<count;i++)
	{
		for(j=0;j<3;j++)
		{
			
				printf("%d ",arr[i][j]);
			
		}
		printf("\n");
	}
	
}
