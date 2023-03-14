//wap to count the numbers ends with 3,5,7 in a given two ranges

#include<stdio.h>
void main()
{
	int n,i,temp,j,count=0,k;
	printf("Enter the no.of ranges:");
	scanf("%d",&n);
	int min[n],max[n];
	for(i=0;i<n;i++)
	{
		printf("enter the %d range min value:",i+1);
		scanf("%d",&min[i]);
		printf("Enter the %d range max value:",i+1);
		scanf("%d",&max[i]);
		if(min[i]>max[i])
		{
			temp=min[i];
			min[i]=max[i];
			max[i]=temp;
		}
		printf("%d\n%d\n",min[i],max[i]);
		for(j=min[i];j<=max[i];j++)
		{
			if(j<10)
			{
				if(j==3||j==5||j==7)
					count++;
			}
			else if(j>9)
			{
				k=j%10;
				if(k==3||k==5||k==7)
					count++;
			}
		}
		printf("Count of %d range-%d\n",i+1,count);
		count=0;
	}
}
	



