//wap to find vowels in a given string

#include<stdio.h>
#include<string.h>
int vowel(char * src);
main()
{
	char src[10];
	int i,l,k,count=0;
	printf("enter a string:");
	scanf("%s",src);
	k=vowel(src);
	printf("vowel count-%d",k);
}


int vowel(char * src)
{
	int i,l,count=0;
	l=strlen(src);
	printf("length of the string %d\n",l);
	for(i=0;i<l;i++)
	{
	   if(src[i]=='a'||src[i]=='e'||src[i]=='i'||src[i]=='o'||src[i]=='u'||src[i]=='A'||src[i]=='E'||src[i]=='I'||src[i]=='O'||src[i]=='U')
		{
			count++;
		}
	}
		
	

	return count;
}
		
