//wap to perform ascii to integer


#include<stdio.h>
char ascii_int(char* src);
main()
{
	int* k;
	char src[10];
	printf("enter the ascii value:");
	scanf("%s",src);
	k=ascii_int(src);
	printf("%d\n",k);
}


char ascii_int(char* src)
{
	int i,l,temp,sum=0;
	l=strlen(src);
	for(i=0;src[i]!='\0';i++)
	{
		if((src[i]>='0')&&(src[i]<='9'))
		{
			temp=src[i]-48;
			sum=sum*10+temp;
		}
	}
	return sum;
}
