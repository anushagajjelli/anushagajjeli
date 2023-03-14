#include<stdio.h>
main()
{
	char x,y,z;
	printf("enter 3 characters\n");
	scanf("%c*%c*%c",&x,&y,&z);
	printf("%d-%c\n%d-%c\n%d-%c\n%p\n%p\n%p\n,x,x,y,y,z,z,x,y,z");
}
