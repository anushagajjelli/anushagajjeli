//wap to sort zeros and 1's in array

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *arr,i,n,j,temp,size;
	printf("Size of the array: ");
	scanf("%d",&size);
	arr=malloc(size*sizeof(int));
	if(arr==NULL)
	{
		printf("Failed to allocate the memory in the heap\n");
		exit(1);
	}
	for(i=0;i<size;i++)
	{
a:
		printf("%d\t Enter the number:",i+1);
		scanf("%d",&n);
		if(n==0||n==1)
			arr[i]=n;
		else
		{
			printf("Invalid input\n");
			goto a;
		}
	}

	for(i=0;i<size/2;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>0)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<size;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	free(arr);
}
