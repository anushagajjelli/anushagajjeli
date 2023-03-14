//wap to kill the wait process .....


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int kill(pid_t,int);
void main()
{
	int ret;
	pid_t pid;
	scanf("%d",&pid);
	ret=kill(pid,2);
}



