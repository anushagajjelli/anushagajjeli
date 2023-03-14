#include<stdio.h>
#include<string.h>
void main()
{
	int i,l,j;
	char src[100],temp;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	l=strlen(src);
	printf("length %d",l);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		temp=src[i];
		src[i]=src[j];
		src[j]=temp;
	}
	printf("%s",src);
}

