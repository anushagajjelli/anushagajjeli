#include<stdio.h>
void main()
{
	char str[100];
	char temp;
	int i,j;
	printf("Enter the string:");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		temp=str[i];
		for(j=i+1;str[j]!='\0';j++)
		{
			if(temp==str[j])
			{
				str[j]=' ';
				str[i]=' ';
			}
		}
	}
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
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
