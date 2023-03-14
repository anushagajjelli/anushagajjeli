#include<stdio.h>
int i=0;
int largest_element(int *ptr,int n,int temp);
void main()
{
	int n,temp;
	int large;
	printf("enter the no.of elements:");
	scanf("%d",&n);
	int ptr[n];
	int j;
	for(j=0;j<n;j++)
	{
		scanf("%d",&ptr[j]);
	}
	temp=ptr[0];
	large=largest_element(ptr,n,temp);
	printf("largest element-%d\n",large);
}


int largest_element(int *ptr,int n,int temp)
{
	for(i=0;i<n;i++)
	{
		if(temp<ptr[i])
		{
			temp=ptr[i];
			temp=largest_element(ptr,n,temp);
		}
	}
	return temp;
}
	
