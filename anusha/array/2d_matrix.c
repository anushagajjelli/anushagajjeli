#include<stdio.h>
#define R 3
#define C 3
void main()
{
	int (*arr)[R];
	int i,j,num;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("ROW %d the value: ",i);
			scanf("%i",&num);
			arr[i][j]=num;
		}
	}
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}

	

