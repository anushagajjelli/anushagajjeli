//wap to verify the kill system call..........which need to kill the other process based on pid no and signal no

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int kill(pid_t,int);
void main()
{
	int ret;
	pid_t pid;
	scanf("%d",&pid);
	ret=kill(pid,2);
}
