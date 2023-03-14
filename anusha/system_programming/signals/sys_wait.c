//wap to verify the wait system call 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
int main()
{
	pid_t pid,cpid;
	int stat=0,i=0,a=1,b=0,c;
//	char *ptr="ANUSHA";
	pid=fork();//to create the child process
	if(pid<0)
	{
		printf("Failed to create the child process");
		exit(1);
	}
	else if(pid>0)
	{
//		sleep(20); //to check the zombie state of child ...after child is terminated
		printf("parent:pid:%d\n",getpid());
		cpid=wait(&stat);
		printf("%d\n",cpid);
		if(WIFEXITED(stat))
			printf("normal termination:%d\n",WEXITSTATUS(stat));
		else if(WIFSIGNALED(stat))
			printf("abnormal termination:%d\n",WTERMSIG(stat));
		else if(WIFSTOPPED(stat))
			printf("stop termination:%d\n",WSTOPSIG(stat));
			
		exit(20);
	}
	else
	{
		printf("child:pid:%d\n",getpid());
		while(i<a)//if infinite loop child is under running and parent is in sleep mode
		{
			printf("hi\n");
//			*(ptr+1)='n';
//			printf("pointer:%c\n",*ptr);//sigsev is recieved by this condition

//			printf("c=%d\n",a/b);//abnormal condition signal 8(sigfpe is passed)
//			printf("hi\t");
			i++;
		}
	//	printf("c=%d\n",a/b);
		exit(50);     //for successful termination the exit value is printed
	}
}
