#include<stdio.h>

void main()
{
	int i;
	int *arr[4];
	int arr0[2];
	int arr1[2];
	int arr2[2];
	int arr3[2];
	arr[0]=&arr0[2];
	arr[1]=&arr1[2];
	arr[2]=&arr2[2];
	arr[3]=&arr3[2];
	printf("Addres of array\n");
	printf("%p\n",&arr0[2]);
	printf("%p\n",&arr1[2]);
	printf("%p\n",&arr2[2]);
	printf("%p\n",&arr3[2]);
	printf("\n");
	for(i=0;i<4;i++)
		printf("%p\n",arr[i]);	
}

