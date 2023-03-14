//wap to print thr transpose matrix using void pointer
#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3
void transpose(int(*ptr)[]);
void main()
{
	int i,j;
	int (*ptr)[3];
	ptr=(int(*)[])malloc((r*c)*sizeof(int));
	void* vptr;
	vptr=transpose;
	((void(*)(int(*)[]))vptr)(ptr);
	
}

void transpose(int(*ptr)[])
{
	int i,j;
	int mat1[r][c];
	int mat2[r][c];
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Before Transpose:\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			mat2[i][j]=mat1[j][i];
		}
	}
	printf("After Transpose\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat2[i][j]);
		}
		printf("\n");
	}
}
