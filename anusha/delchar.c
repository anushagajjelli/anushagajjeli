#include<stdio.h>
#include<string.h>
void main()
{
	int i,j,k=0,l;
	char src[50],temp;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	l=strlen(src);
	printf("length-%d\n",l);
	for(i=0;src[i]!='\0';i++)
	{
		temp=src[i];
		for(j=i+1;src[j]!='\0';j++)
		{
			if(temp==src[j])
			{
				
				src[j]='*';
			}
		
		}
			temp='*';
		
	
	}
	printf("before:%s\n",src);
	for(i=0;src[i]!='\0';i++)
	{
		if(src[i]!='*')
		 {
			 src[k]=src[i];
			 k++;
		}
	}
	src[k]='\0';
	printf("after:%s",src);

}

