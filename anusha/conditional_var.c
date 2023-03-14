#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mtx =PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond =PTHREAD_COND_INITIALIZER;
void * thread1();
void * thread2();
int global=0;
void main()
{
	pthread_t t1,t2;
	//sleep(5);
	pthread_create( &t1,0,&thread1,NULL);
	//sleep(5);
	pthread_create( &t2,0,&thread2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("global=%d\n",global);

	exit(EXIT_SUCCESS);
}
void *thread1()
{
	for(;;)
	{
		pthread_mutex_lock(&mtx);
		pthread_cond_wait(&cond,&mtx);
		global++;
		printf("global after thread1=%d\n",global);
		pthread_mutex_unlock(&mtx);
		if(global>=10)
			return(NULL);
	}
}
void *thread2()
{
	for(;;)
	{
		pthread_mutex_lock(&mtx);
		if(global<3||global>6)
		{
			//signal to free waiting thread by freeing the mutex.
			//now thread1 is permitted to modify "global".
			pthread_cond_signal(&cond);
		}
		else
		{
			global++;
			printf("global after thread2=%d\n",global);
		}
		pthread_mutex_unlock(&mtx);
		if(global>=10)
			return(NULL);
	}
}
