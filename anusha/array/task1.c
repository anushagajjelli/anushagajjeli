//Wap to find the given number is divisible by 8 or not

#include<stdio.h>
main()
{
	int arr[5];
	int i;
	for(i=0;i<5;i++)
	{
		printf("enter the inputs:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]%8==0)
		{
			printf("\n%d is divisible by 8",arr[i]);
		}
		else
			printf("\n%d is not divisible by 8",arr[i]);
	}
}
