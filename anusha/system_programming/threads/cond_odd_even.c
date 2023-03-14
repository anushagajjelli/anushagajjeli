#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int count = 0,n=50;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void  *printEven(void *arg);
void *printOddNum(void *arg);

void *printEvenNum(void *arg)
{   
    while(count < n)
    {
        pthread_mutex_lock(&mutex);

        while(count % 2 != 0)
        {   
            pthread_cond_wait(&cond, &mutex);// it act as an blocking call for this thread1.
        }
        printf("even:-%d\n", count++);
	sleep(1);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);// it act as an wakeup call for the thead2.
    }
}
void *printOddNum(void *arg)
{   
    while(count < n)
    {
        pthread_mutex_lock(&mutex);
        while(count % 2 != 1)
        {   
            pthread_cond_wait(&cond, &mutex);// it act as an blocking call for  this thread2.
        }
        printf("odd:-%d\n", count++);
	sleep(1);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);// it will act as an wakeup call for thread1
    }
}
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_mutex_init(&mutex, 0);
    pthread_cond_init(&cond, 0);
    pthread_create(&thread1, 0,printEvenNum, NULL);
    pthread_create(&thread2, 0, printOddNum, NULL);
    printf("Address by function name:%p\n",printEvenNum);
    printf("Address:%p\n",&printEvenNum);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return  0;
}

