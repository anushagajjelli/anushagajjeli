//wap to create the shell commands using exec family calls

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
void main()
{
	int i=0,l,k=0,j=0,stat;
	pid_t pid;
	char arr[50];
	char *ptr[50];
	printf("Enter the string:");
	scanf("%[^\n]s",arr);
	l=strlen(arr);
	for(i=0;i<=l;i++)
	{
		if((arr[i]==' ')||(i==l))
		{
			arr[i]='\0';
			ptr[j]=arr+k;
		//	ptr[j][i]='\0';
			k=i+1;
			j++;
		}
	}
	pid=fork();
	if(pid<0)
	{
		printf("failedto create child\n");
		exit(1);
	}
	if(pid>0)
	{
		wait(&stat);
		printf("parent is running\n");
	}
	else
	{
		printf("child process is running\n");
		printf("%d\n",getpid());
		execvp(ptr[0],ptr);
	}

}

	

