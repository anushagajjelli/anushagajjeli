//wap to print the string

#include<stdio.h>
#include<string.h>
void string(char* str,char c,char r);
void main()
{
	char str[100];
	int c,r;
	printf("enter the string\n");
	__fpurge(stdin);
	scanf("%s",str);
	printf("select the character\n");
	__fpurge(stdin);
	scanf("%c",&c); 
	printf("replace the character\n");
	__fpurge(stdin);
	scanf("%c",&r);
	string(str,c,r);
}

void string(char* str,char c,char r)
{
	int i,j;
	for(i=0;str[i]!='\0';i++)
	{
			if(str[i]== c)
			{
				str[i]= r;
			}
	}
	printf("%s\n",str);
	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]==r)&&(str[i+1]==r))
		{
			for(j=i;str[j]!='\0';j++)
			{
				str[j]=str[j+1];
			}
			i--;
		}
	}
	printf("%s",str);
}
				
