#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void myhandler(int signo);

void main()
{
	int i=0,ret;
       
	printf("pid=%d\n",getpid());
	ret=signal(SIGINT,SIG_IGN);
	sleep(10);
	while(i<=1000000000000)
	{
		sleep(1);
		printf("i=%d\n",i);
		i++;
	}
}



void myhandler(int signo)
{
	printf("signo=%d\n",signo);
	sleep(5);
	printf("my handler is done");

}
