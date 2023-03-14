//wap to print the upper traingle using matrix

#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3
void uppermat(int(*ptr)[3]);
void main()
{
	int(*ptr)[3];
	ptr=(int(*)[])malloc((r*c)*sizeof(int));
	void* vptr;
	vptr=uppermat;
	((void(*)(int(*)[]))vptr)(ptr);
}


void uppermat(int(*ptr)[3])
{
	int i,j;
	int mat[r][c];
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
	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(((i==1)&&(j==0))||((i==2)&&(j==0))||((i==2)&&(j==1)))
				{
					mat[i][j]=mat[i][j]-mat[i][j];//now lower elements becomes zero by subtracting
				}
				else
					mat[i][j];
			}
		}
	}
	printf("After changing the upper matrix triangle\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
		printf("\n");
	}
}
