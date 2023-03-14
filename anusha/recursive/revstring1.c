//wap for reverse string by using recursive function

void revstring(char* str,int i,int j );
#include<stdio.h>
#include<string.h>
void main()
{
	char str[100];
	//char rev[100];
	printf("Enter the string:");
	scanf("%[^\n]s",str);
	int i,j,l;
	l=strlen(str);
	i=0;
	j=l-1;
	printf("main:fact(%s)\n",str);
	revstring(str,i,j);
	printf("main: %s\n",str);
}

void revstring(char* str,int i,int j )
{
	char res[100],temp;
	
	
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
		if(i<j)
		{
			revstring(str,i,j);
		}
	
	
}
