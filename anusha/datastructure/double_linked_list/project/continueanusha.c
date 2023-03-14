#include<stdio.h>
void main()
{
	int i=0;
	int n=5;
	for(i=0;i<n;i++)
	{
		if(i==3)
		{
			printf("Anusha\n");
			continue;
		}
		printf("%d ",i);
	}
}
