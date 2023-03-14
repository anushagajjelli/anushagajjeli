//wap to perform the uppercase letters to lowercase letters
//......................................In this process....1st we write the data in parent,simultaneously child reads the data present in parent ....
//.........................In child process the modifications are performed(it writes the data/ modified as per requirement in child process)...then it reads in the parent process as per pipes concept. 


#include<stdio.h>
#include<string.h>
//#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	int ret,ret1,ret2,i=0;
	int fd[2],fd1[2];
	char buf[100];
	printf("Enter the string:");
	scanf("%[^\n]s",buf);
	ret=pipe(fd);
	ret1=pipe(fd1);
	
	if(ret<0)
	{
		printf("Failed to send the data\n");
		exit(1);
	}

	printf("return value of pipe-1:%d\n",ret);
	printf("return value of pipe-2:%d\n",ret1);

	pid=fork();

	printf("return value of pid:%d\n",pid);
	if(pid<0)
	{
		printf("Failed to create the child\n");
		exit(1);
	}
	else if(pid>0)
	{
		printf("............................PARENT PROCESS..............................\n");
		close(fd[0]);
		close(fd1[1]);
		ret=write(fd[1],buf,strlen(buf));
		perror("write");
		if(ret<0)
		{
			printf("Failed to write the data\n");
			exit(2);
		}
		printf("Write in parent process\n");
		close(fd[1]);
			
		sleep(3);
		printf("....................After toggling the data from child.................\n");
		printf("READ IN PARENT PROCESS\n");
		read(fd1[0],buf,strlen(buf));
		perror("read");
		//printf("parent:%s\n",buf);
		write(1,buf,strlen(buf));
		close(fd1[0]);

	}

	else
	{
		printf("...................................CHILD PROCESS.......................\n");
		close(fd[1]);
		close(fd1[0]);

		ret=read(fd[0],buf,strlen(buf));
		printf("Read in child process\n");
		if(ret<0)
		{
			printf("Failed to read the data in child\n");
			exit(3);
		}
	//	buf[ret1]='\0';
		close(fd[0]);
		sleep(2);

		for(i=0;buf[i]!='\0';i++)
		{
			if(buf[i]>='A' && buf[i]<='Z')
				buf[i]=buf[i]+32;
			else if(buf[i]>='a' && buf[i]<='z')
				buf[i]=buf[i]-32;
		}

		ret=write(fd1[1],buf,strlen(buf));
		printf("write in child process to toggle the data\n");
		perror("write");
		printf("child:%s\n",buf);


	}
}







