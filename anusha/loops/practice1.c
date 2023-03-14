//wap to reverse_integer using array:

#include<stdio.h>
#define NM 5
void reverse(int *ptr,int n);
main()
{
	int arr[NM];
	int i,j,temp;
	for(i=0;i<NM;i++)
	{
		printf("enter the input\n");
		scanf("%d",&arr[i]);
	}
	printf("array size is %d bytes\n",sizeof(arr));
	printf("address of the array %p\n",&arr);
	reverse(arr,5);
}

void reverse(int *ptr,int n)
{
	int i,j,temp;
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp=ptr[i];
		ptr[i]=ptr[j];
		ptr[j]=temp;
	}
	printf("THE REVERSE INTEGER:\n");
	for(j=0;j<n;j++)
	printf("%d\n",ptr[j]);
}
			
