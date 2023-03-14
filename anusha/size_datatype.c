//wap to find the size of datatype without using sizeof operator

#include<stdio.h>
void main()
{
	int *ptr,*ptr1;
	int a;
	ptr=&a;
	ptr1=(&a)+1;
	printf("%d\n",ptr1-ptr);
}
	
