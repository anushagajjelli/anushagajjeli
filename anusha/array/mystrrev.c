//wap to perform the  reverse the word


#include<stdio.h>
char* mystrrev(char *);
main()
{
	char src[30];
	char* rev;
	printf("enter the string:");
	scanf("%s",src);
	rev=mystrrev(src);
	printf("%s\n",rev);
	
}


char* mystrrev(char *src)
{
	int i,j,l,temp;
	l=strlen(src);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		temp=src[i];
		src[i]=src[j];
		src[j]=temp;
	}
	return src;
}
		
		
	
