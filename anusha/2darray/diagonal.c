//wap to print the diagonal elements using matrix

#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3
void diagonal(int(*mat)[3]);
void main()
{

	int mat[r][c];	
	diagonal(mat);
}


void diagonal(int(*mat)[3])
{
	int i,j;
	//int mat[r][c];
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Before change\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
	}
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(i!=j)
			{
				mat[i][j]=' ';
				//printf("%c\t",mat[i][j]);
			}
			else
				mat[i][j];
		}
	}
	
	printf("After changing the digonal matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			if(mat[i][j]==' ')
			{
				printf("%c\t",mat[i][j]);
			}
			else
				printf("%d\t",mat[i][j]);

				
		}
		printf("\n");
	}
}
