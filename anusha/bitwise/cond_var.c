/* program to understand conditional vars*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
void* thread_1(void* arg);
void* thread_2(void* arg);
int glob=0;
void main()
{
	int loop=100,res,i;
	void* ret;

	

void thread_1(void *)
{
	int loop, local;

	int i;
	for(i = 0; i < loop; i++)
	{	
		pthread_mutex_lock(&mtx);
		if(glob < 10)
		{
			pthread_cond_wait(&cond, &mtx);
		}
		local = glob;
		local++;
		glob=local;
		pthread_mutex_unlock(&mtx);

	}

}

