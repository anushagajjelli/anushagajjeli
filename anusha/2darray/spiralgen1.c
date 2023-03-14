
//wap to print the output of the spiral matrix using functions

#include<stdio.h>
#define R 6
#define C 6
void sprialmat(int (*mat)[6]);
main()
{
	int mat[R][C];
	int i,j,m,n;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	sprialmat(mat,mat1);
}

void sprialmat(int (*mat)[6])
{
	int i,j,m,n,count=0;
	for(m=0,n=(C-1);m<=n;m++,n--)
	{
		for(i=m;i<=n;i++)
		{
			printf("%d " ,mat[m][i]);
			
			count++;
			
				if(count%C==0)
					printf("\n");
			
		}
		for(i=m+1;i<=n;i++)
		{
			printf("%d  ",mat[i][n]);
			count++;
			if(count%C==0)
					printf("\n");
		}
		for(i=(n-1);i>=m;i--)
		{
			printf("%d  ",mat[n][i]);
			count++;
			if(count%C==0)
					printf("\n");
			
		}
		for(i=(n-1);i>=(m+1);i--)
		{
			printf("%d  ",mat[i][m]);
			
			count++;
			if(count%C==0)
					printf("\n");
			
		}
	}
}
