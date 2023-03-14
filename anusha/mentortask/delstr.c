//wap to delete the string'

#include<stdio.h>
#include<string.h>
void del_str(char * src,char c);
main()
{
	
	char src[100];
	char c;
	printf("enter the string:");
	__fpurge(stdin);
	scanf("%[^\n]s",src);
	printf("enter the character to delete:");
	__fpurge(stdin);
	scanf("%c",&c);
	del_str(src,c);
	//printf("%s\n",src);

}

void del_str(char * src,char c)
{
	int i,j,l,count=0;
	l=strlen(src);
	printf("length of the string-%d\n",l);
	for(i=0,j=0;i<l;i++)
	{
		//printf("enter the loop:");
		if(src[i]!=c)
			{
				src[j++]=src[i];
				//printf("enter the loop:");
			}
		else if(src[i]==c)
		{
			count++;
		}
	}
		src[j]='\0';
	//return src;
	if(count==0)
		printf("entered charcater is not found\n");
	else 
		printf("%s\n deleted element count is  %d times",src,count);
	
}

