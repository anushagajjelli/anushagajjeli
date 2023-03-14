//....................................wap to perform the semaphore......................
//.........................................CLIENT.......................................

#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>

#define KEY 0x1998866
void main()
{
	int shmid,semid,ret;
	char *ptr;
	struct sembuf anu;
	while(1)
	{

	shmid=shmget(KEY,512,0);
	 if(shmid<0)
         {
                 printf("failed to create shared memory\n");
                 exit(1);
          }

	semid=semget(KEY,2,0);
	 if(semid<0)
          {
                    printf("failed to create a counters in kernel\n");
                     exit(2);
           }


	ptr=shmat(shmid,NULL,0);
//	strcpy(ptr,"Hello");



	printf("enter the string:");
         scanf("%[^\n]",ptr);
         __fpurge(stdin);

	anu.sem_num=0;
        anu.sem_op=+1;//counter-1 value is incremented
        anu.sem_flg=0;

	semop(semid,&anu,1);

         anu.sem_num=1;
         anu.sem_op=-1;
         anu.sem_flg=0;

         ret=semop(semid,&anu,1);

         printf("client side recieved is :%s\n",ptr+256);//print from second 256 bytes
         }

	
//	shmdt(ptr);
}

