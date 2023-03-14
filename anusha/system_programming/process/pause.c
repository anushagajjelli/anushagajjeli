//wap to perform the pause system call

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void main()
{
	int i=0;
	while(i<=100)
	{
		printf("%d\n",i);
		pause();
		i++;
	}
}
