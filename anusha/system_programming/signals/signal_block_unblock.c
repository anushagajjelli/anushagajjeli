//wap to block and unblock the signals

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void main()
{
	int i=0;
	sigset_t signalset;
	sigemptyset(&signalset);//clear the signal
	sigaddset(&signalset,2);//it sets the bit at 2
	sigaddset(&signalset,14);//it sets the 14th bit
	sigprocmask(SIG_BLOCK,&signalset,NULL);//2 and 14th signals are blocked....now can't perform the signal
	printf("%d\n",getpid());
	while(i<50)
	{
		sleep(1);
		printf("%d\n",i);
		if(i==20)
		{
			sigdelset(&signalset,14);//delete the 14th bit ...then 14th bit is in block state only
			sigprocmask(SIG_UNBLOCK,&signalset,NULL);//unblocks the 2nd bit now
		}
		i++;
	
	
	}
	//sigset_t signalset;
//	sigemptyset(&signalset);
	sigprocmask(0,NULL,&signalset);//it is in unblock state

}
