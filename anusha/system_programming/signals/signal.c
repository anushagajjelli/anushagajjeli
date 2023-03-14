//wap to verify the signal and check its state

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int x=1;
main()
{
	int pid;
	 pid=getpid();
        printf("%d\n",pid);
	sleep(5);
	while(x>0)
	{
		printf("Hi\t");
		x++;
	}
}
