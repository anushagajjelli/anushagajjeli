//verify the threads....create the thread...
//pthread_join is similar to wait()
//............If one thread doesn't ultilise the time,another thread ultilize that time................................
//........................Thread works simultaneously...................................

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void* mythread(void* ptr);
int  main()
{
	pthread_t ti;
	int i=0,ret,loop=10;
	ret=pthread_create(&ti,0,mythread,&loop);
	pthread_join(ti,NULL);
	while(i<10)               //this loop will print for 10times and terminate the process if no blocking call is used in the main function....
	{
	//	sleep(1);
		printf("Main thread is alive\n");
		i++;
	}
//	sleep(1);
	//sleep(10);//it goes into sleep for given time,so the time is ultilized by another function i.e. mythread function (for 10sec)
//	exit(0);//if no sleep and exit then nothing is printed
//	pthread_exit(&ret);//when we call this function in main function,even the main function is terminated the remaining threads or function will continue the execution
}

void* mythread(void* ptr)
{
	int i;
//	sleep(2);
	printf("My thread is invoked\n");
	for(i=0;i<=*(int*)ptr;i++)
	{
		sleep(1);
	//	if(i%100==0)
			printf("%d\n",i);
	}

}
