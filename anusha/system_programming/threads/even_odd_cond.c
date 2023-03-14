#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_cond_t dove=PTHREAD_COND_INITIALIZER;
pthread_mutex_t dumb=PTHREAD_MUTEX_INITIALIZER;

int packet=7;

void *cinthol(void *buf);
void *lifebouy(void *buf);

void main()
{
	pthread_t lux1,lux2,lux3;
	int lot1,lot2,lot3;
         
	lot1=pthread_create(&lux1,0,cinthol,NULL);
	lot2=pthread_create(&lux2,0,lifebouy,NULL);


	pthread_join(lux1,0);
	pthread_join(lux2,0);


	printf("lot1=%d\tlot2=%d\t,lot3=%d\t\n",lot1,lot2,lot3);

       
}

void *cinthol(void *buf)
{
	 int shampoo=100;

	 while(packet<shampoo)
	 {
		 pthread_mutex_lock(&dumb);
		 if(packet%2==0)
		 {
			 //pthread_cond_signal(&dove);
			 printf("even number=%d\n",packet++);
			 pthread_cond_signal(&dove);
		 }
		 else
			 pthread_cond_wait(&dove,&dumb);
		 pthread_mutex_unlock(&dumb);
	 }
}

void *lifebouy(void *buf)
{
         int shampoo=100;

         while(packet<shampoo)
         {
                 pthread_mutex_lock(&dumb);
                 if(packet%2==1)
                 {
			 //pthread_cond_signal(&dove);
                         printf("odd number=%d\n",packet++);
			 pthread_cond_signal(&dove);
                 }
                 else
                         pthread_cond_wait(&dove,&dumb);
                 pthread_mutex_unlock(&dumb);
         }
}



