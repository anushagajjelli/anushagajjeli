//Wap to count the repeated elements in given array and print the non-repeated elements

#include<stdio.h>
int nonrepeated_elements(int *ptr,int num);
void main()
{
	int arr[10];
	int i,j,count=0;
	for(i=0;i<10;i++)
	{
	printf("enter the inputs:");
	scanf("%d",&arr[i]);
	}
	nonrepeated_elements(arr,10);
}

int nonrepeated_elements(int *ptr,int num)
{
	int i,j,count=1;
	for(i=0;i<10;i++)
	{
		if(ptr[i]!=' ')
		{
			for(j=i+1;j<10;j++)
			{
					if(ptr[i]==ptr[j])
					{
						count++;
						ptr[j]=' ';
					}
					
			}
			
			if(count==1)
			{
				printf("non-repeated element %d \n",ptr[i]);
			}
			
			count=1;
		}
		
	}
			           	
}
	
	