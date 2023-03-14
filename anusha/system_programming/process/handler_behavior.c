//wap to change the behavior of the process

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int);
void main()
{
	int i=0;
	signal(SIGINT,myhandler);
	while(i<100)
	{
		sleep(1);
		printf("inifinty loop %d\n",i);
		i++;
	}
}

void myhandler(int signo)
{
	printf("%d\n",signo);
}
