//wap to print the output of the spiral matrix

#include<stdio.h>
#define R 4 
#define C 4
void main()
{
	int i,j;
	int mat1[R][C];
	//int mat2[r][c];
	for (i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("Enter the matrix [%d][%d]:",i,j);
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Matrix before change\n");
	for(i=0;i<R;i++,printf("\n"))
	{
		for(j=0;j<C;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
	}
	printf("Matrix after change\n");
	i=0;
	for(j=0;j<C;j++)
		printf("%d\t",mat1[i][j]);
	j=3;
	for(i=1;i<R;i++)
		printf("%d\t",mat1[i][j]);
	i=3;
	for(j=2;j>=0;j--)
		printf("%d\t",mat1[i][j]);
	j=0;
	for(i=2;i>=1;i--)
		printf("%d\t",mat1[i][j]);
	i=1;
	for(j=1;j<=2;j++)
		printf("%d\t",mat1[i][j]);
	i=2;
	for(j=2;j>=1;j--)
		printf("%d\t",mat1[i][j]);
		
}
