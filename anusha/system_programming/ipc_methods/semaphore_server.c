//................................wap to perform the semaphore ..........................
//.........................................SERVER.........................................

#include<sys/sem.h>
#include<sys/ipc.h>
#include<sys/shm.h>
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
		shmid=shmget(KEY,512,IPC_CREAT|0660);//allocate 512 memory in shared memory

		if(shmid<0)
		{
			printf("failed to create shared memory\n");
			exit(1);
		}

		semid=semget(KEY,2,IPC_CREAT|0660);//dividing the 512 into 2 partitions
		if(semid<0)
		{
			printf("failed to create a counters in kernel\n");
			exit(2);
		}


		ret=semctl(semid,0,SETVAL,0);//initializing the counter-0...set val ->set the count value to1
	//	printf("return value of counter-1:%d\n",ret);

		ret=semctl(semid,1,SETVAL,0);//initializing the counter-1 ...set counter-1 value to 1
	//	printf("return value of counter-2:%d\n",ret);

		anu.sem_num=0;//0->index
		anu.sem_op=-1;//counter-0 value is decremented
		anu.sem_flg=0;

		ret=semop(semid,&anu,1);//perform the operation
		if(ret!=0)
		{
			printf("failed to do operations\n");
			exit(1);
		}


		//printf("return value of semop:%d\n",ret);

		ptr=shmat(shmid,NULL,0);//to access the shared memory ,it should attach with the process

		printf("server side recieved is:%s\n",ptr);


		printf("enter the string:");
		scanf("%[^\n]",ptr+256);//as we taking 512bytes...both client and server as 256 bytes ...for server ptr's base address get by ptr name...for client is to scan from the ptr+256 

		__fpurge(stdin);

		anu.sem_num=1;
		anu.sem_op=1;
		anu.sem_flg=0;

		ret=semop(semid,&anu,1);

//		shmdt(ptr);
	}
}





