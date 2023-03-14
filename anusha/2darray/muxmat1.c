//wap to print the multiplication of the matrix using void pointer

#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 4
#define r1 4
#define c1 2
void multiplication(int(*ptr)[3],int(*ptr1)[3]);
void main()
{
	int i,j;
	int (*ptr)[3];
	int (*ptr1)[3];
	ptr=(int(*)[])malloc((r*c)*sizeof(int));
	ptr1=(int(*)[])malloc((r*c)*sizeof(int));
	void * vptr;
	vptr=multiplication;
	((void(*)(int(*)[]))vptr)(ptr,ptr1);
	
	
}


void multiplication(int(*ptr)[3],int(*ptr1)[3])
{
	int i,j,k;
	int mat1[r][c];//first matrix 3*4
	int mat2[r1][c1];//second matrix 4*2
	int mat3[r][c1];//res...max 3*2(r*c1)
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter the matrix mat2(%d*%d)\n",r1,c1);
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("First matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
	}
	printf("Second matrix\n");
	for(i=0;i<r1;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",mat2[i][j]);
		}
	}
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			mat3[i][j]=0;
			for(k=0;k<c;k++)
				mat3[i][j]=mat3[i][j]+mat1[i][k]*mat2[k][j];
		}
	}
	printf("Multiplication of the matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			printf("%d  \t",mat3[i][j]);
		}
		printf("\n");
	}
}
