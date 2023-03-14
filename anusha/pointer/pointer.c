/*wap of pointer using int datatype:*/

/*#include<stdio.h>
main()
{
	int x=10;
	int *ptr=NULL;
	ptr=&x;
	*ptr=20;
	printf("%p-%d-%d-%d\n",&x,x,sizeof(&x),sizeof(x));
	printf("%p-%d\n",ptr,sizeof(ptr));
	printf("%d-%d\n",*ptr,sizeof(*ptr));
	printf("%p-%d\n",&ptr,sizeof(&ptr));
}*/



/*wap of pointer using char datatype:*/

/*#include<stdio.h>
main()
{
	char x=10;
	char *ptr=NULL;
	ptr=&x;
	*ptr=30;
	printf("%p-%d-%d-%d\n",&x,x,sizeof(&x),sizeof(x));
	printf("%p-%d\n",ptr,sizeof(ptr));
	printf("%d-%d\n",*ptr,sizeof(*ptr));
	printf("%p-%d\n",&ptr,sizeof(&ptr));
	printf("%d-%d\n",*ptr,sizeof(ptr));
	printf("%d-%d\n",ptr,sizeof(*ptr));
}*/


/*#include<stdio.h>
main()
{
	char x=10;
	int *ptr=NULL;
	ptr=&x;
	*ptr=30;
	printf("%p-%d-%d-%d\n",&x,x,sizeof(&x),sizeof(x));
	printf("%p-%d\n",ptr,sizeof(ptr));
	printf("%d-%d\n",*ptr,sizeof(*ptr));
	printf("%d\n",*ptr);
	printf("%d\n",ptr);
	printf("%p-%d\n",&ptr,sizeof(&ptr));
	printf("%d-%d\n",*ptr,sizeof(ptr));
	printf("%d-%d\n",ptr,sizeof(*ptr));
}*/

/*wap of pointer using float datatype:*/

/*#include<stdio.h>
main()
{
	float x=15;
	float *ptr=NULL;
	ptr=&x;
	*ptr=50;
	printf("%f\n",x);
	printf("%f-%d-%d\n",x,sizeof(&x),sizeof(x));
	printf("%p-%d\n",ptr,sizeof(ptr));
	printf("%f-%d\n",*ptr,sizeof(*ptr));
	printf("%p-%d\n",&x,sizeof(&ptr));
	printf("%f-%d\n",*ptr,sizeof(ptr));
	printf("%p-%p-%d\n",&x,ptr,sizeof(*ptr));
}*/


#include<stdio.h>
main()
{
	double x=10;
	double *ptr;
	ptr=&x;
	*ptr=30;
	printf("%lf\n",x);
	printf("%p\n",&x);
	printf("%d\n",sizeof(x));
	printf("%d\n",sizeof(&x));
}


/*#include<stdio.h>
main()
{
	float x=10;
	float *ptr;
	ptr=&x;
	*ptr=60;
	printf("%f\n",x);
	printf("%d\n",sizeof(x));
	printf("%d\n",sizeof(&x));
	printf("%f\n",&x);
}*/




















