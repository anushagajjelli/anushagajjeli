#include<stdio.h>
int main()
{
	int fact=1,i,n;
	printf("enter a number:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		fact =fact*i;
		
	}
	printf("factorial od %d is %d",n,fact);
	return 0;
}
