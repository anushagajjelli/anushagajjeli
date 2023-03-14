//wap to perform the fibonacci series

#include<stdio.h>
void main()
{
	int n1=1,n2=1,n3,n,i;
	printf("enter the range:");
	scanf("%d",&n);
	printf("%d\t%d\t",n1,n2);
//	for(i=0;i<n-2;i++)
	for(i=2;i<n;i++)
	{

		n3=n1+n2;
		printf("%d\t",n3);
		n1=n2;
		n2=n3;
	}
}


