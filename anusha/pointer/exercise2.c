
#include<stdio.h>
main()
{
	int arr[5]={30,40,12,34,65};
	int x=15;
	int *ptr=arr;
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*ptr++;//1
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=++*ptr;//2
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*++ptr;//3
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=(*ptr)++;//4
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=++(*ptr);//5
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*(ptr++);//6
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*(++ptr);//7
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=--*ptr;//8
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*(ptr--);//9
	printf("%p-%d-%d\n",ptr,*ptr,x);
	x=*--ptr;//10
	printf("%p-%d-%d\n",ptr,*ptr,x);
}	
	
