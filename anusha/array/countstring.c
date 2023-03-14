//wap to print how many times a string is repeated

#include<stdio.h>
void count_string(char*);
main()
{
	char src[100];
	printf("enter the string:");
	scanf("%[^\n]s",src);
	count_string(src);
}

void count_string(char* src)
{
	//char src[100];
	int i,j,count;
	for(i=0;src[i]!='\0';i++)
	{
		if(src[i]==' ')
		{
			continue;
		}
		count=1;
		for(j=i+1;src[j]!='\0';j++)
		{
			if(src[i]==src[j])
			{
				count++;
				src[j]=' ';
			}
		}
		printf("%c-%d\n",src[i],count);
	}
}


