//wap to perform the upper to lower and lower to upper case when space is found

#include<stdio.h>
#include<string.h>
void char_case(char *ptr);
main()
{
	char ptr[100];
	printf("Enter the string\n");
	scanf("%[^\n]s",ptr);
	char_case(ptr);
}

void char_case(char *ptr)
{
 	int i,l,j,k=0,m;
 	l=strlen(ptr);
 	for(i=0;i<=l;i++)
 	{
		if((ptr[i]==' ')||(i==l))
		{
			j=i-1;
			//m=i+1;
			//k=0;
			if((ptr[j]>='A')&&(ptr[j]<='Z'))
				ptr[j]=ptr[j]+32;
			else if((ptr[j]>='a')&&(ptr[j]<='z'))
				ptr[j]=ptr[j]-32;
			if((ptr[k]>='A')&&(ptr[k]<='Z'))
				ptr[k]=ptr[k]+32;
			else if((ptr[k]>='a')&&(ptr[k]<='z'))
				ptr[k]=ptr[k]-32;
				k=i+1;
 		}
 		//k=i+1;
 	}
 	printf("%s",ptr);
 }
