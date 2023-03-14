#include<stdio.h>
#include<stdio_ext.h>
void main()
{
	int n,n1,i,sum=0;
	scanf("%d",&n);
	__fpurge(stdin);
	scanf("%d",&n1);
	for(i=n+1;i<=n+n1;i++)
	{
		printf("%d\n",i);
		sum=sum+i;
	}
	printf("sum-%d\n",sum);
}	
