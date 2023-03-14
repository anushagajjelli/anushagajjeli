//wap to perform the  reverse the word


#include<stdio.h>
char* mystrrev(char *src);
main()
{
	char src[100];
	char* rev;
	printf("enter the string:");
	scanf("%[^\n]s",src);
	rev=mystrrev(src);
	printf("%s\n",rev);
	
}


char* mystrrev(char *src)
{
	int i,j,l,temp;
	l=strlen(src);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		if(src[i]=' ')
		{
			continue;
		}
			temp=src[i];
			src[i]=src[j];
			src[j]=temp;
	}
	return src;
}
		
		
