#include<stdio.h>
/*void main()
{
	int arr[10]={1,2,2,3,2,4,5,4,6,7};
	int i,j,c=0;
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
				if(arr[i]==arr[j])
				{
					c++;
				}
		}
		if(c>0)
			printf("%d",arr[i]);
		c=0;
	}
}*/
#define MAX(x,y) (x)>(y)?(x):(y)
main()
{
	int i=10,j=5,k=0;
	k=MAX(i++,++j);
	printf("%d %d %d",i,j,k);
}
	
