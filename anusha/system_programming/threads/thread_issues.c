//wap to perform the thread synchronization issues

#include<pthread.c>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int glob=0;
void main()
{
	void* ret;
	pthread_t t1,t2;
	int res,loop=2000;
	pthread_create(&t1,0,thread_fun1,&loop);
	pthread_create(&t2,0,thread_fun2,&loop);
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	printf("%d\n",glob);
}

void* thread_fun1(void* arg)
{
	int loop,i,local;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		local=glob;
		local++;
		glob=local;
	}
}



void* thread_fun1(void* arg)
{
	int loop,i,local;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		local=glob;
		local++;
		glob=local;
	}
}
