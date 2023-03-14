//wap to perform doule pointer

#include<stdio.h>
main()
{
	int x=10;
	int* ptr=&x;
	int** dptr=&ptr;
	printf("%p\n",ptr);
	printf("ptr size %d\n",sizeof(&x));
	printf("ptr size %d\n",sizeof(x));
	printf("%p\n",&x);
	printf("%p\n",&ptr);
	printf("&ptr size %d\n",sizeof(&ptr));
	printf("%d\n",*ptr);
	printf("%p\n",dptr);
	printf("%p\n",&dptr);
	printf("%d \n",**dptr);
	printf("%p\n",*dptr);
}
