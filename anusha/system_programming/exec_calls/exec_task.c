//wap to create the shell commands using exec family calls

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
void main()
{
	int i=0,l,k=0,j=0;
	char arr[50];
	char *ptr[30];
	printf("Enter the string:");
	scanf("%[^\n]s",arr);
	l=strlen(arr);
	for(i=0;i<=l;i++)
	{
		if((arr[i]==' ')||(i==l))
		{
			ptr[j]=arr+k;
		//	ptr[j][i]='\0';
			if(i==l)
				arr[i+1]='\0';
			else
				arr[i]='\0';
			k=i+1;
			j++;
		}
	}
	execvp(ptr[0],ptr);
	//execv("/home/engineer/anusha/system_programming/exec","exec");
/*	for(i=0;i<j;i++)
	
		printf("%s\n",ptr[i]);
	printf("Entered\n");*/
}

