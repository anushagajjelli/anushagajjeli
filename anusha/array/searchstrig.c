//wap to search a string

#include<stdio.h>
#include<string.h>
//#include<stdio_ext.h>
int mystrcmp(char*,char*,int);
main()
{
	int i,j,k,cmp,count=0;
	char src[100];
	char dst[100];
	printf("enter the string:");
	scanf("%[^\n]s",&src);
	__fpurge(stdin);
	printf("enter the string to be searched:");
	scanf("%[^\n]s",&dst);
	__fpurge(stdin);
	i=strlen(src);
	j=strlen(dst);
	printf("%d-%d\n",i,j);
	for(k=0;k<=(i-j);   )
	{
		cmp=mystrcmp(&src[k],dst,j);
		if(cmp==0)
		{
			count++;
			k=k+j;
		}
		k++;
	}
	if(count!=0)
		printf("string is found-%d\n",count);
	else
		printf("not found\n");
}
/*mystrlen(char* len)
{
	int j;
	for(j=0;len[j]!='\0';j++);
	return j;
}*/

int mystrcmp(char* cmp1,char* cmp2,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(cmp1[i]!=cmp2[i])
			return 1;
	}
	return 0;
}
