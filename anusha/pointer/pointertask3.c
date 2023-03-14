//wap to find least second value in an array

#include<stdio.h>
#define NM 5
void second_least(int *ptr,int n);
void main()
{
	int arr[NM];
	//int *ptr;
	int i,j,t;
	for(i=0;i<NM;i++)
	{
		printf("enter the input\n");
		scanf("%d",&arr[i]);
	}
	second_least(arr,NM);
}
void second_least(int *ptr,int n)
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
	
	printf("second_least number:");

	printf("%d",((int *)ptr)[1]);
}
