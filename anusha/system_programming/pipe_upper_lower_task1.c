//wap to perform the uppercase letters to lowercase letters
//......................................Using a single pipe............................
//......................................Write in parent process and read in child process................................

#include<stdio.h>
#include<string.h>
//#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	int ret,ret1,ret2,i=0;
	int fd[2];
	char buf[100];
	printf("Enter the string:");
	scanf("%[^\n]s",buf);
	ret=pipe(fd);
//	ret1=pipe(fd1);
	pid=fork();
	if(pid<0)
	{
		printf("Failed to create the child\n");
		exit(1);
	}
	else if(pid>0)
	{
		ret=write(fd[1],buf,strlen(buf));
		if(ret<0)
		{
			printf("Failed to write the data\n");
			exit(2);
		}
		close(fd[1]);

	}

	else
	{
		ret=read(fd[0],buf,strlen(buf));
	//	buf[ret1]='\0';
		close(fd[0]);
		for(i=0;buf[i];i++)
		{
			if(buf[i]>='A' && buf[i]<='Z')
				buf[i]=buf[i]+32;
			else if(buf[i]>='a' && buf[i]<='z')
				buf[i]=buf[i]-32;
		}
		write(1,buf,ret);//printing the string
	}
}







