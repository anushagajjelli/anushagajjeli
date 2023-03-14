#include<stdio.h>
//#define MAX 10
int copy_elements(int* arr,int* arr1,int n);
main()
{
	int arr[10],i,res,n;
	int arr1[10];
	printf("enter the size of the string:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the inputs:");
		__fpurge(stdin);
		scanf("%d",&arr[i]);
	}
	res = copy_elements(arr,arr1,n);
	for(i=0;i<(n-res);i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
	for(i=0;i<res;i++)
	{
		printf("%d",arr1[i]);
	}
}

int copy_elements(int* arr,int* arr1,int n)
{
	
	int temp=0,res=0,i,j,k,l;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				k=j;
				l=j+1;
				arr1[res]=arr[i];
				res++;
				for(l,k;k<n;k++,l++)
				{
					arr[k]=arr[l];
				}
				n--;
			}
		}
	}
	return res;
}






































/*int src[10],NM,AA;
	int str[10];
	int i,j=0,k=0,l=0;
	for(i=0;i<MAX;i++)
	{
		for(j=i+1;j<MAX;j++)
		{
			if(arr[i]!=arr[j])
			{
				str[l]=arr[j];
				printf("original elements %d\n",str[l]);
				l++;
			}
			else if(arr[i]==arr[j])
			{
				src[k]=arr[j];
				k++;
				
			}	

		}
		
	}
	//AA=l;
	//for(i=0;i<AA;i++)
	//printf("original elements %d\n",str[i]);
	NM=k;
	for(i=0;i<NM;i++)
	printf("duplicate elements %d\n",src[i]);
}*/
