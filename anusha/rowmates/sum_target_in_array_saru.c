//wap to add any two numbers in an array which is equal to given target by user and print their index values

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int arr[5];
	int target,i,j;
	int count=0;
	for(i=0;i<5;i++)
	{
		printf("Enter the array:");
		scanf("%d",&arr[i]);
	}
	printf("Enter the target value:");
	scanf("%d",&target);
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[i]+arr[j]==target)
			{
				printf("index values[%d:%d]\n",i,j);
				count++;
				break;
			}
			
		}
	}
	if(count==0)
		printf("Element not found\n");
}


