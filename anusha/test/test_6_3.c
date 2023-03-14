//wap to print the largest and second largest in the given array

#include<stdio.h>
void main()
{
	int arr[5],temp=0,i,temp1=0;
	for(i=0;i<5;i++)
	{
		printf("Enter the elements in an array\n");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<5;i++)
	{
		if(temp<arr[i])
			temp=arr[i];
	}
	printf("Largest element in an array-%d\n",temp);
	for(i=0;i<5;i++)
	{
		if(temp>arr[i]&&temp1<arr[i])
			temp1=arr[i];
	}
	printf("Second largest element in given array-%d",temp1);
}
