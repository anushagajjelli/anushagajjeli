//wap to print the biggest element in given array and also last element

#include<stdio.h>
void main()
{
	int arr[5];
	int res=0,i,j;
	for(i=0;i<5;i++)
		{
			scanf("%d",&arr[i]);
		}
	for(i=0;i<5;i++)
	{
//		for(j=i+1;j<5;j++)
//		{
			if(res<arr[i])
				res=arr[i];
//		}
		
	}
	printf("leader element %d\n",res);
		printf("last element %d",arr[i-1]);
}	
