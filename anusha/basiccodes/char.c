#include<stdio.h>
main()
{
	char x,y,z;
	printf("enter three characters\n");
	scanf("%c*%c*%c",&x,&y,&z);
	printf("%d-%c\n%d-%c\n%d-%c\n",x,x,y,y,z,z);
}
