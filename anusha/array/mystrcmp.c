//wap to perform string comparison


#include<stdio.h>
int mystrcmp(char *,char *);
main()
{
	int str;
	char src1[20];
	char src2[20];
	printf("enter the first string:");
	scanf("%s",&src1);
	printf("enter the second string:");
	scanf("%s",&src2);
	str=mystrcmp(src1,src2);
	if(str==0)
		printf("the strings are same:");
	else
		printf("the strings are not same:");
	
}

int mystrcmp(char* src1,char* src2)
{
	int i,l1,l2;
	if((src1==NULL)||(src2==NULL))
		return -1;
	l1=strlen(src1);
	l2=strlen(src2);
	if(l1!=l2)
	{
		return -1;
	}
	for(i=0;src1[i]!='\0';i++)
	{
		if(src1[i]!=src2[i])
			return -1;
	}
	return 0;
}
	
			
	
