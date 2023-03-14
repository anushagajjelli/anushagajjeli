//wap to print only the string by removing the special characteristics and numbers

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char src[32];
	int len,i,j,k=0;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	len=strlen(src);
	printf("length of string:%d\n",len);
	char str[len];
	for(i=0;i<len;i++)
	{
		if(!((src[i]>='a'&& src[i]<='z')||(src[i]>='A' && src[i]<='Z')))
		{
		//	printf("Hi");
			//str[k]=src[i];
			//k++;
			for(j=i;src[j]!='\0';j++)
			{
				src[j]=src[j+1];
				i--;
			}
		}

	}
	//str[k]='\0';
	printf("string:%s",src);
}


