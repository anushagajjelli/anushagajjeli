#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define MAX 10
#define COUNT_MIN 3
#define COUNT_MAX 7
int count=0;
pthread_mutex_t count_mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;
void* threadfun1();
void* threadfun2();
void main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread_fun1,NULL);
	pthread_create(&t2,0,threadfun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Final count-%d\n",count);
}

void* threadfun1()
{
	int i;
	for( ; ;)
	{
		pthread_mutex_lock(&count_mutex);
		pthread_count_wait(&cond_var,&count_mutex);
		count++;
		printf("Count of threadfun1 -%d\n",count);
		pthread_mutex_unlock(&count_mutex);
		if(count >= MAX)
