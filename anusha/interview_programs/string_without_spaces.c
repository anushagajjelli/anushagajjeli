//wap to print the string without the extra spaces

#include<stdio.h>
#include<string.h>
void main()
{
	char src[100],temp;
	int i,j,k,m=0,len;
	printf("Enter the string:");
	scanf("%[^\n]s",src);
	len=strlen(src);
	printf("Length:%d\n",len);

/*	for(i=0;i<len;i++)
	{
		if((src[0]=' '))
		{
			k=i;
			for(j=i+1;j<len;j++)
			{
				src[k]=src[j];
				k++;
			}
			src[k]='\0';
			i=0;
		}
		else if((src[i]==' ')&&(src[i+1]==' '))
		{
			k=i;
			for(j=i+1;j<len;j++)
			{
				src[k]=src[j];
				k++;

			}
			src[k]='\0';
			
		}
	}*/


	for(i=0;src[i]!='\0';i++)
	{
		if(((src[i-1]==' ')||(i==0))&&(src[i]==' '))
		{
			for(j=i;src[j]!='\0';j++)
			{
				src[j]=src[j+1];
			}
			i--;
		}
	}
	i--;

	if((src[i]==' ')&&(src[i+1]=='\0'))
		src[i]=src[i+1];
	printf("%s\n",src);
}


