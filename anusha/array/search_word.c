//wap to search the word from the given string

#include<stdio_ext.h>
#include<string.h>
void main()
{
	char src[100];
	char res[30];
	int l1,l2,i,j,b=0,count=0;
	printf("Enter the string:");
	scanf("%[^\n]s",src);

	printf("Enter the word in given string:");
	__fpurge(stdin);
	scanf("%s",res);
	
	l1=strlen(src);
	l2=strlen(res);

	for(i=0;i<l1;  )
	{
	
		for(j=0;j<l2;  )
		{
			if(src[i+j]==res[j])
				b++;
			j++;
		}

		if(j==b)
			count++;

		b=0;
		i++;
	}
	
	if(count==0)
		printf("sub string is not present\n");
	else
		printf("string is present:%d\n",count);
}






