//wap to change the behavior of the signal by using sigaction

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void myhandler(int);
void main()
{
	int i=0;
	struct sigaction act;//structure datatype
	act.sa_handler=myhandler;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);//sa as signal mask
	sigaddset(&act.sa_mask,14);//add 2 and 14 bits
	sigaddset(&act.sa_mask,2);
	sigprocmask(SIG_BLOCK,&act.sa_mask,0);//block 2 and 14 bits
	sigaction(14,&act,0);//changing the behavior of 2 

	printf("%d\n",getpid());

	while(i<=20)
	{
		sleep(1);
		printf("%d\n",i);//check using kill signal
		i++;
	}

	sigdelset(&act.sa_mask,2);//14 is in block state
	//sigdelset(&act.sa_mask,2);//when 2 is block the sigalrm 14 is unblocked 
	sigprocmask(SIG_UNBLOCK,&act.sa_mask,0);//unblocked signal 2
	//alarm(3);//alarm perform after 3sec and terminate the process when 14 is unblocked
	sleep(4);
	i=0;
	while(i<=20)
	{
		sleep(1);
		printf("%d\n",i);//check the signal 2 and 14
		i++;
	}
}

void myhandler(int signo)
{
	printf("signal-%d is received\n",signo);//after 1st while loop the signal-2 behavior changes to handler function
}
