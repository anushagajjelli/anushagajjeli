//wap to print the addition of the matrix

#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3
void addition(int(*ptr)[3]);
void main()
{
	int i,j;
	int (*ptr)[3];
	ptr=(int(*)[])malloc((r*c)*sizeof(int));
	addition(ptr);
}


void addition(int(*ptr)[3])
{
	int i,j;
	int mat1[r][c];
	int mat2[r][c];
	int mat3[r][c];
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter the matrix mat2(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			mat3[i][j]=mat1[i][j]+mat2[i][j];
			printf("addition of matrix %d \t",mat3[i][j]);
		}
	}
}
	
