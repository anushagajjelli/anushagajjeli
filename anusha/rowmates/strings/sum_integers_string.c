//wap to print the sum of integers in the given string......

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char src[32];
	int len,i,sum=0;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	len=strlen(src);
	printf("Length of the string:%d\n",len);
	for(i=0;i<len;i++)
	{
		if((src[i]>='0') && (src[i]<='9'))
			sum=sum+src[i]-48;
	}
	printf("%d",sum);
}


