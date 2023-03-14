//wap to perform cancatenation using strings

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
void concatenate(char*,char*);
main()
{
	int n,m;
	printf("Enter n,m values:");
	scanf("%d %d",&n,&m);
	__fpurge(stdin);
	char a[n];
	char b[m];
	printf("enter the string:\n");
	scanf("%[^\n]s",&a);
	__fpurge(stdin);
	printf("enter the string to be searched:\n");
	scanf("%[^\n]s",&b);
	__fpurge(stdin);
	concatenate(a,b);
}

void concatenate(char* ptr1,char* ptr2)
{
	int l1,l2,len,i,j;
	l1=strlen(ptr1);
	l2=strlen(ptr2);
	len=l1+l2;
	for(i=l1,j=0;i<len;i++,j++)
	{
		ptr1[i]=ptr2[j];
	}
	ptr1[i]='\0';
	//for(i=0;ptr1[i]!='\0';i++)
	//{
		printf("%s\n",ptr1);
	//}
}
