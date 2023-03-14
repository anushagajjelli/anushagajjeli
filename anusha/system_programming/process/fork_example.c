//wap to check the pid (processor id ) and ppid(parent processor id) of orphan process............

#include<unistd.h>
#include<stdio.h>
main()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		printf("parent: %d\n",getpid());
		printf("parent :child process pid:%d\n",pid);
	}
	else
	{
		sleep(10);
		printf("child:%d\n",getpid());
		printf("child:%d\n",getppid());
		printf("child:%d\n",pid);
		
	}
}
