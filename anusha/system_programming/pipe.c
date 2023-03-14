//wap to perform the example of a pipe
//................................close the read in parent and perform the write operation at parent...................................
//.................................Close the write at child process to access the parent data and perform read operation at child.................

#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void main()
{
	pid_t pid;
	int fd[2];
	char buf[100];
	int ret,ret1;
	ret=pipe(fd);//fd->array name
	pid=fork();
	if(pid<0)
	{
		printf("Failed to create child process\n");
		exit(0);
	}
	else if(pid>0)
	{
		//close(fd[0]);
		printf("...........This is Parent process.............\n");
		ret=write(fd[1],"Hello",strlen("Hello"));
		perror("WRITE");
		printf("Return value-%d\n",ret);
		//close(fd[1]);
		exit(1);
	}
	else
	{
		//close(fd[1]);
		printf("...........This is child process................\n");
		ret1=read(fd[0],buf,100);
		printf("Read %d\n",ret1);
		perror("read");
		write(1,buf,ret1);
		//close(fd[0]);
		exit(2);
	}
}

