//wap to use fork sytem call 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int x=10;
main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("Failed to create child\n");
		exit(1);
	}
	else if(pid>0)      //parent process
	{
	//	sleep(5); //if sleep is given  parent process then chils process will execute first...parent process is under waiting queue
		printf("%p-%d\n",&x,x);//both child and parent have same virtual address
		exit(0);
	}
	else          //child process
	{
		sleep(5);             //sleep in child process ...then executes the parent process first...child is under waiting queue...
		x=20;
		printf("%p-%d\n",&x,x);
		exit(0);
	}
}
