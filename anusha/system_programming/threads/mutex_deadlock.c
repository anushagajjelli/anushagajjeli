//wap to perform the condition variables for even and odd numbers

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t mutex1 =PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;
void*  threadfun1();
void* threadfun2();
int count=0;
int num=0;
void main( )
{
	pthread_t t1,t2;
	pthread_create(&t1,0,threadfun1,NULL);
	pthread_create(&t2,0,threadfun2,NULL);
	pthread_join(t1,0);
	pthread_join(t2,0);

	printf("Final output:%d\n",count);
}

void* threadfun1()
{
	int  i=100;

	while(count<i)
	{
		pthread_mutex_lock(&mutex1);
		if(count%2==0)
		{
			
			printf("Even  Numbers printed from threadfun1-%d\n",count);
		        count++;
		 }
		 pthread_mutex_lock(&mutex2);
		 num++;
		 printf("Number printed by threadfun1-%d\n",num);
		 pthread_mutex_unlock(&mutex2);
		 
		pthread_mutex_unlock(&mutex1);
		if(count>50)
			exit(1);
	}
}

void* threadfun2()
{
	int i=100;
	while(count<i)
	{
		pthread_mutex_lock(&mutex1);
		if(count%2==1)
		{
			printf("Odd Numbers printed by threadfun2-%d\n",count);
			count++;
		     
		}
		pthread_mutex_lock(&mutex2);
		num++;
		printf("Numbers printed by thredfun2-%d\n",num);
		pthread_mutex_unlock(&mutex2);
		
		pthread_mutex_unlock(&mutex1);
		if(count>50)
			exit(2);
	}
}
