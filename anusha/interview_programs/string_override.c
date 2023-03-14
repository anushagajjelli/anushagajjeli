//wap to implement the I/P:-AnushA123@# .................->O/P:-anusha

#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
void main()
{
	int l,i;
	char src[100];
	char dst[100];
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	l=strlen(src);
	printf("Length:%d\n",l);
	for(i=0;i<=l;i++)
	{
		if(((src[i]>=65)&&(src[i]<=90))||((src[i]>=97)&&(src[i]<=122)))
		{
			if((src[i]>=65)&&(src[i]<=90))
			{
				dst[i]=src[i]+32;
			}
			else
				dst[i]=src[i];
		}
	}
	printf("OUTPUT:%s",dst);
}
	
