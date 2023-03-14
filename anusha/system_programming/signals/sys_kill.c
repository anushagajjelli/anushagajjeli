
//wap to verify the kill system call..........which need to kill the other process based on pid no and signal no

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
	while(1)
		printf("%d\n",getpid());
}
