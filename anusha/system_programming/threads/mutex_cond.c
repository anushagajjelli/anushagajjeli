//wap to perform mutex with condition variable

#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void* thread_fun1(void* arg);
void* thread_fun2(void* arg);
int global=0;
pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;
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
		pthread_cond_wait(&cond_var,&mtx);
                local=global;
                local++;
                global=local;
		printf("global value at threadfun2-%d\n",global);
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
		if(global<1000||global>1500)
		{
			pthread_cond_signal(&cond_var);
		}
		else
		{
               		 local=global;
               		 local++;
              		  global=local;
			  printf("Global value at threadfun2-%d\n",global);
		}
                pthread_mutex_unlock(&mtx);
        }
}
