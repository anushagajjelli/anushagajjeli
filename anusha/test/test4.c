//was to toggle the characters

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int toggle_string(char* str);
main()
{
	int c;
	char *str[100];
	//char outsut[100];
	printf("enter the string:");
	scanf("%s",str);
	c=toggle_string(str);
	//printf("count of the toggled element %d",c);
}


int toggle_string(char* str)
{
	int l,i,count=0;
	//char* outsut[100];
	l=strlen(str);
	for(i=0;i<l;i++)
	{
		if((str[i]>='A')&&(str[i]<='Z'))
			{
				/*outsut[i]=str[i]+32;
				count++;*/
				str[i]=str[i]+32;

			}
		else if((str[i]>='a')&&(str[i]<='z'))
			{
				/*outsut[i]=str[i]-32;
				count++;*/
				str[i]=str[i]-32;

			}
		else if(str[i]=='$')
			{
			       str[i]='#';
				count++;
			}
		else if(str[i]=='%')
			{
				str[i]='&';
				count++;
			}
		else if(str[i]=='(')
			{
			str[i]=')';
			count++;
			}
		else if(str[i]=='*')
			{
				str[i]='+';
				count++;
			}
		else if(str[i]=='@')
			{
			str[i]='~';
			count++;
			}
		else if(str[i]==' ')
			{
				str[i]='^';
				count++;
			}
          printf("%c",str[i]);
	}
	
	return count;
}		
