//wap to print the single repeated element in the given array by using the bitwise operations

#include<stdio.h>
#include<stdlib.h>
#define MAX 11
void main()
{
	int arr[MAX];
	int i,res=0,res1=0,temp;
	printf("Enter the array elements:");
	for(i=0;i<MAX;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<MAX;i++)
	{
		if(res1==0)
		{
			i=i+1;//i value is incremented to i=1
			res1++;//to work for single case 
			res=(arr[0]^arr[i]);
		}
		else 
		{
			res=(res^arr[i]);
		}
	}
	printf("single repeated element:%d\n",res);
}


	
