#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

//int pthread_create(pthread_t *thread,const pthread_attr_t *attr,void*(*start)buf,void *buf);
//pthread_t (variable declaration);

char *jerom(char *buf);
char *jerom1(char *buf);

pthread_mutex_t vyram=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t dhanush;

int ram=10;

void main()
{
	pthread_t suraj;
	int s;
        char buf[100]="iam jerom suraj";

	pthread_cond_init(&dhanush,NULL);

	s=pthread_create(&suraj,NULL,jerom,buf);
	s=pthread_create(&suraj,NULL,jerom1,buf);


	pthread_join(suraj,NULL);

	if(s!=0)
	{
	    printf("failed to create a thread\n");
	    //errEXITEN(s,"pthread_create");
	}
	printf("return value of s=%d\n",s);

	pthread_cond_destroy(&dhanush);
	printf("ram=%d\n",ram);
}

char *jerom(char *buf)
{
	int n=10,i,ram;
	printf("childthread is invoked\n");
	//pthread_cond_wait(&dhanush,&vyram);
	pthread_mutex_lock(&vyram);
	pthread_cond_wait(&dhanush,&vyram);
        for(i=0;i<n;i++)
	{
		ram++;
	}
        
	printf("%s\n",buf);
	pthread_mutex_unlock(&vyram);
	pthread_cond_signal(&dhanush);
}


char *jerom1(char *buf)
{
	int i,n=20,ram;
	printf("childthread2 is invoked\n");
	//pthread_cond_signal(&dhanush);
	pthread_mutex_lock(&vyram);
	pthread_cond_wait(&dhanush,&vyram);
        for(i=0;i<n;i++)
	{
		ram++;
	}

	printf("%s\n",buf);
	pthread_mutex_unlock(&vyram);
	pthread_cond_signal(&dhanush);
}



