#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char src[100],temp;
	int l,i,j,k=0;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	l=strlen(src);
	printf("Length of string:%d\n",l);
	for(i=0;i<=l;i++)
	{
		if((src[i]==' ')||(i==l))
		{
			for(j=i-1,k;j>k;j--,k++)
			{
				temp=src[k];
				src[k]=src[j];
				src[j]=temp;
			}
			k=i+1;
		}
		//k=i+1;
	}
	printf("%s",src);
}

