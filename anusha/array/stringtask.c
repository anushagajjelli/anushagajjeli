//wap to print the string

#include<stdio.h>
#include<string.h>
void string(char* str);
void main()
{
	char str[100];
	printf("enter the string\n");
	scanf("%s",str);
	string(str);
}

void string(char* str)
{
	int i,j;
	for(i=0;str[i]!='\0';i++)
	{
			if(str[i]=='e')
			{
				str[i]='u';
			}
	}
	printf("%s\n",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==str[i+1])
		{
			for(j=i;str[j]!='\0';j++)
			{
				str[j]=str[j+1];
			}
		}
	}
	printf("%s",str);
}
				
	
