//wap to delete the repeated character in a given string

#include<stdio.h>
void del_repeatedchar(char* str);
void main()
{
	char str[100];
	int count=0;
	printf("Enter the string:");
	scanf("%s",str);
	del_repeatedchar(str);
}


void del_repeatedchar(char* str)
{
	int i,j,count=0,k=0;
	for(i=0;str[i]!='\0';i++)
	{
		count=0;
		for(j=i+1;str[j]!='\0';j++)
		{
			if(str[i]==str[j])
			{
				count++;
			}
		}
		if(count!=0)
		{
			for(j=i+1;str[j]!='\0';j++)
			{
				if(str[i]==str[j])
				{
					str[j]='*';
				}
			
			}
			str[i]='*';
		}
		
	}
	//str[i]='*';
	printf("%s\n",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!='*')
		{
			str[k]=str[i];
			k++;
		}
	}
	str[k]='\0';
	printf("after deletion:%s",str);
}
