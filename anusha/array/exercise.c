
#include<stdio.h>
#define SIZE 10
void repeated(int arr[],int n);
main()
{
	int i;
	int arr[SIZE];
	for(i=0;i<SIZE;i++)
	{
		printf("enter the arr[%d]:",i);
		scanf("%d",&arr[i]);
	}

	repeated(arr,SIZE);
}





void repeated(int *arr,int n)
{
	int i,j,big,count1,count2=0;
	for(i=0;i<n;i++)
	{
		count1=1;
		for(j=i+1;j<n;j++)
		{
			//if(arr[i]>arr[j])
			//{
				if(arr[i]==arr[j])
				{
					count1++;
					
				}
			//}
		}
		if(count2<count1)
		{
			big=arr[i];
			count2=count1;
		}
		else 
			big=arr[i];
	
	}
	printf("%d-%d\n",big,count2);
}
			
