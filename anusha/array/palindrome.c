//wap to print palindrome using strings

#include<stdio.h>
#include<string.h>
int palindrome(char *src);
main()
{
	int k,i,j,count=0;
	char src[10];
	printf("enter the inputs:");
	scanf("%s",&src);
	palindrome(src);
}


int palindrome(char *src)
{
	int i,j,count=0;	
	
	for(i=0,j=(strlen(src)-1);i<j;i++,j--)
	{
		if(src[i]!=src[j])
		{
			count=0;
		}
		else if(src[i]==src[j])
		{
			count=1;
		}
		//return count;
	}
	if(count==1)
		printf("palindrome:");
	else
		printf("not palindrome:");
}
