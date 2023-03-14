
//accessing by address
/*#include<stdio.h>
main()
{
	const char x=10;
	char* ptr=&x;
	printf("%d\n",x);
	*ptr=11;
	printf("%d\n",x);
}*/



//constant data

/*#include<stdio.h>
main()
{
	int x=10;
	int y=20;
	const int* ptr;
	ptr=&x;
	printf("%d\n",x);
	int *ptr1=30;
	ptr=&y;
	printf("%d\n",*ptr);
}*/

//constant address

/*#include<stdio.h>
main()
{
	int x=10;
	int * const ptr=&x;
	*ptr=20;
	int y=30;
	//ptr=&y;
	printf("%p\n",ptr);
	printf("%d\n",x);
}*/

//const data const address

#include<stdio.h>
main()
{
	int x=10;
	int y=20;
	const int const *ptr=&x;
	*ptr=20;
	ptr=&y;
	printf("%d",x);
}
	
	
