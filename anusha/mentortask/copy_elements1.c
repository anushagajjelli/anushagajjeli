#include<stdio.h>
//#define MAX 10
void copy_elements(int* arr,int* arr1,int n);
main()
{
	int arr[10],i,n;
	int arr1[10];
	printf("enter the size of the string:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the inputs:");
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	copy_elements(arr,arr1,n);
	
}

void copy_elements(int* arr,int* arr1,int n)
{
	
	int temp=0,dup=0,i,j,l,k;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				k=j;
				l=j+1;
				arr1[dup]=arr[i];
				dup++;
				for(l,k;k<n;k++,l++)
				{
					arr[k]=arr[l];
				}
				n--;
			}
		}
	}
	for(i=0;i<(n-dup);i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	for(i=0;i<dup;i++)
	{
		printf("%d",arr1[i]);
	}
}


