//wap to print first and second largest numbers in an array

#include<stdio.h>
#define MAX 5
void first_second_largest(int *ptr,int n);
void main()
{
	int i,j,temp;
	int arr[MAX];
	for(i=0;i<MAX;i++)
	{
	printf("enter the inputs:");
	scanf("%d",&arr[i]);
	}
	first_second_largest(arr,MAX);
}
		
	



void first_second_largest(int *ptr,int n)
{
	
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(ptr+j) < *(ptr+i))
			{
				t=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=t;
			}
				
		}
	}
	printf("ascending value \n");
	for(i=0;i<n;i++)
		printf("%d\t",*(ptr+i));
	printf("\n biggest value %d\n",ptr[n-1]);
	printf(" second biggest value %d\n",ptr[n-2]);
}

		
	

































































