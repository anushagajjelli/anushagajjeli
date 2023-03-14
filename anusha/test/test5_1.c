//wap to 05421987610-i/p and o/p-3 in an unsorted array

#include<stdio.h>
void missing_element(int arr[11]);
void main()
{
	int arr[11]={0,5,4,2,1,9,3,8,7,10};
	missing_element(arr);
}

void missing_element(int arr[11])
{
	int res[11];
	int i,j,temp;
	int count=0;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		printf("%d ",arr[i]);
	}
	printf("\n");
	/*for(i=0;i<=10;i++)
	{
			if(i==arr[i])
			{
				count++;
			}
			
	}*/
	for(i=0;i<=10;i++)
	{
		temp=arr[i+1]-arr[i];
		if(temp==2)
		{
			printf("missing element-%d\n",arr[i+1]-1);
			break;
		}
		else if(temp>1)
		{
			printf("missing element-%d\n",arr[i]+1);
			printf("missing element-%d\n",arr[i+1]-1);
			break;
		}
	}

}
