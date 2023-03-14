//wap to perform search and replace

#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>
int mystrcmp(char* ,char*,char*,int);
void replace(char *,char*);
main()
{
	int i,j,k,count=0;
	int status;
	char src[100];
	char src1[100];
	char src2[100];
	printf("enter the string:");
	scanf("%[^\n]s",src);
	__fpurge(stdin);
	printf("enter the string to be searched:");
	__fpurge(stdin);
	scanf("%[^\n]s",src1);
	printf("enter the string to be replace:");
	__fpurge(stdin);
	scanf("%[^\n]s",src2);
	i=strlen(src);
	j=strlen(src1);
	for(k=0;k<=(i-j); )
	{
		status=mystrcmp(&src[k],src1,src2,j);
		replace(src,src2);
		if(status==0)
		{
			count++;
			k=k+j;
		}
		//replace(src,src2);
		k++;
		
	}
	if(count!=0)
		printf("string is found-%d\n",count);
	else
		printf("not found\n");
	
	//replace(src,src2);
	printf("%s",src);
}

int mystrcmp(char* src,char* src1,char* src2,int j)
{
	int i;
	for(i=0;i<j;i++)
	{
		if(src[i]!=src1[i])
			return 1;
	}
	return 0;
	
}
void replace(char *s1,char *s2)
{
	int i,r;
	char temp;
	for(i=0;(s1[i]!='\0')&&(s2[i]!='\0');i++)
	{
		temp=s1[i];
		s1[i]=s2[i];
		s2[i]=temp;
	}
	if(s2[i]!='\0')
	{
		for(r=i;s2[r]!='\0';r++)
			s1[r]=s2[r];
		//s1[r]='\0';
		s2[i]='\0';
	}
	else if(s1[i]!='\0')
	{
		for(r=i;s1[r]!='\0';r++)
			s2[r]=s1[r];
		//s2[r]='\0';
		//s1[i]='\0';
	}
	//else
		//s1[i]=s2[i]='\0';
}
			
