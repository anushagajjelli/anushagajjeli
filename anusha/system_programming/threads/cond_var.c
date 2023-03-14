//wap to perform the condition variables using the mutex

#include<stdio.h>

#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t mtx;
pthread_cond_t cond;
void*  threadfun1();
void* threadfun2();
int global=0;
void main( )
{
	pthread_t t1,t2;
	pthread_mutex_init(&mtx,NULL);
	pthread_cond_init(&cond,NULL);

	pthread_create(&t1,0,threadfun1,NULL);
	pthread_create(&t2,0,threadfun2,NULL);

	pthread_join(t1,0);
	pthread_join(t2,0);
	
	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&cond);
	printf("Final output:%d\n",global);
}

void* threadfun1()
{
	int  i=100;

	while(global<i)
	{
		pthread_mutex_lock(&mtx);
		if(global>19&&global<40)
		{
			pthread_cond_wait(&cond,&mtx);
		}
		printf("Numbers printed from threadfun1-%d\n",global++);
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&cond);
		if(global>60)
			exit(0);
	}
}

void* threadfun2()


{
	int i=100;
	while(global<i)
	{
		pthread_mutex_lock(&mtx);
		if(global>39 && global<61)
		{
			pthread_cond_wait(&cond,&mtx);
		}
		printf("Numbers printed by threadfun2-%d\n",global++);
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&cond);
		if(global>60)
			exit(1);
	}
}

			
		


	
