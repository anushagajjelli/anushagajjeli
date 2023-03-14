//wap to perform string cantentation

#include<stdio.h>
#include<string.h>
void concatenation(char *,char *);
void main()
{
	char src[20];
	char src1[20];
	printf("enter the first string:");
	scanf("%d",&src);
	printf("enter the second string:");
	__fpurge(stdin);
	scanf("%d",&src1);
	concatenation(src,src1);
}

void concatenation(char *src)
{
	int i,j,k,l,sum=0;
	for(i=0;src[i]!='\0';i++);
	for(j=0;src1[j]!='\0';j++);
	for(k=0,l=0;k<=src[i];k++,l++)
	{
		src[i]=src[j];
		for(i=0;i<(i+j);i++)
		{
			printf("%c",src[i]);
		}
	}
}
	
		
			

	
