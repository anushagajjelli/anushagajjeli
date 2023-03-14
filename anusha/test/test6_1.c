#include<stdio.h>
//#define M 10
void largest(int *arr,int n);
void main()
{
	int i,arr[10];
	for(i=0;i<10;i++)
	{
		printf("Enter the elemets of array:");
		scanf("%d",&arr[i]);
	}
	largest(arr,10);
}

void largest(int *arr,int n)
{
	int big=0,lbig=0;
	int i=0;
	while(n!=0)
	{
		if(arr[i]>big)
		{
			big=arr[i];
			lbig=big;
		}
		n--;
		i++;
	}

	printf("Shortest-%d",lbig);
	printf("Biggest-%d",big);
}
		
