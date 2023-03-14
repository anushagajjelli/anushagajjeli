//wap to print the output of the spiral matrix

#include<stdio.h>
#define R 5
#define C 5
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
	for(m=0,n=(C-1);m<=n;m++,n--)
	{
		for(i=m;i<=n;i++)
			printf("%d " ,mat[m][i]);
		for(i=m+1;i<=n;i++)
			printf("%d  ",mat[i][n]);
		for(i=(n-1);i>=m;i--)
			printf("%d  ",mat[n][i]);
		for(i=(n-1);i>=(m+1);i--)
			printf("%d  ",mat[i][m]);
	}
	printf("\n");
}
