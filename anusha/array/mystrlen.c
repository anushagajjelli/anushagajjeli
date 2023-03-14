//wap to find the strlen()

#include<stdio.h>
int mystrlen(char*);
main()
{
	char src[10];
	char dst[10];
	int l;
	printf("enter the string:");
	scanf("%s",src);
	l=mystrlen(src);
	printf("the string length is %d",l);
}

int mystrlen(char*)
{
	int i;
	for(i=0;src[i]!='\0';i++);
		return i;
}



main()
{
	//fptr=mystrlen;
	char src[10];
	//char dst[10];
	int l;
	//fptr=mystrlen;
	printf("enter the string:");
	scanf("%s",src);
	fptr=mystrlen;
	l=fptr(src);
	printf("the string length is %d",l);
}

int mystrlen(char*src)
{
	int i;
	for(i=0;src[i]!='\0';i++);
		return i;
}
