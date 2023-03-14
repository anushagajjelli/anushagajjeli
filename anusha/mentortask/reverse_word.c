//wap to reverse the words in given string

#include<stdio.h>
#include<string.h>
void reverse_word(char * src);
main()
{
	//char rev;
	char src[100];
	printf("enter the string:");
	scanf("%[^\n]s",src);
	reverse_word(src);
	
}

void reverse_word(char * src)
{
	int i,j,l;
	int k=0,temp;
	l=strlen(src);
	printf("length of the string-%d\n",l);
	for(i=0;i<=l;i++)
	{
		if((src[i]==' ')||(i==l))
		{
			for(j=(i-1),k;j>k;k++,j--)
			{
				temp=src[k];
				src[k]=src[j];
				src[j]=temp;
			}
			k=i+1;
		}
	}
	printf("REVERSE STRING -%s",src);
}
