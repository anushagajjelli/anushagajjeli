//wap to check whether a string is palindrome or not

#include<stdio.h>
#include<string.h>
void main()
{
	char src[32];
	int len,i,j;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	len=strlen(src);
	printf("length of string:%d\n",len);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		if(src[i]!=src[j])
			break;
	}
	if(i==j)
		printf("palindrome");
	else
		printf("not palindrome");

}
	
