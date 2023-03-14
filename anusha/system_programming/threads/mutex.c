//wap to perform the mutex locking for threads

#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void* thread_fun1(void* arg);
void* thread_fun2(void* arg);
int global=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
void main()
{
	pthread_t t1,t2;
	int res,loop=2000;
	void* ret;
	pthread_create(&t1,0,thread_fun1,&loop);
	pthread_create(&t2,0,thread_fun2,&loop);
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	printf("%d\n",global);
}

void* thread_fun1(void* arg)
{
	int local,i,loop;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mtx);
		local=global;
		local++;
		global=local;
		pthread_mutex_unlock(&mtx);
	}
}



void* thread_fun2(void* arg)
{
	int local,i,loop;
	loop=*(int*)arg;
	for(i=0;i<loop;i++)
	{
		pthread_mutex_lock(&mtx);
		local=global;
		local++;
		global=local;
		pthread_mutex_unlock(&mtx);
	}
}
