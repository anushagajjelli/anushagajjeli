//wap to check pid and ppid 

#include<stdio.h>
#include<unistd.h>
main()
{
	int pid,ppid;
	//pid_t pid,ppid;
	pid=getpid();
	printf("%d\n",pid);
	ppid=getppid();
	printf("%d\n",ppid);
	while(1);
}
