//wap to replace the special character with tthe eqiuvalent decimal number

#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char *src;
	int n,i;
	printf("Enter the size:");
	scanf("%d",&n);
	src=(char*)malloc(n*sizeof(char));
	if(src==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(0);
	}
	printf("Enter the string:");
	__fpurge(stdin);
	scanf("%[^\n]s",src);

	for(i=0;src[i]!='\0';i++)
	{
		if(!(((src[i]>='a')&&(src[i]<='z'))&&((src[i]>='A')&&(src[i]<='Z'))&&(src[i]==' ')))
		{
			
		}
	}
	printf("%s\n",src);
}



