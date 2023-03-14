//wap to perform string copy function...strcpy()


#include<stdio.h>
#include<string.h>
char* mystrcpy(char* dst,char* src);
main()
{
	char src[20];
	char dst[20];
	char* str;
	printf("enter the string:");
	scanf("%s",src);
	str=mystrcpy(dst,src);
	printf("%s\n",str);
	
}

char* mystrcpy(char* dst,char* src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dst[i]=src[i];
		//dst[i]='\0';
	}
	dst[i]=src[i];
	//printf(" in function %s",dst[i]);
	return dst;
}
