//wap for reverse string by using recursive function

#include<stdio.h>
#include<string.h>
void revstring(char* str,int i,int j );
void main()
{
	char str[100];
	//char rev[100];
	printf("Enter the string:");
	scanf("%s",str);
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
	
		if(i<j)
		{
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
	
	revstring(str,i+1,j-1);
	}
	//printf("revstring(%s)->return string %s\n",str,res);
	//return res;
}
