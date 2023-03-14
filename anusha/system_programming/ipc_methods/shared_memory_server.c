//................................................Wap to perform the shared memory................................................
//....................................................SERVER................................................................
#include<stdio_ext.h>
#include<unistd.h>
#include<sys/shm.h>
#include<stdlib.h>

#define KEY 0x1998800
void main()
{
	int shmid,ret;
	char *ptr;//because when you want to attach some data into shared memory,we need to use  shmat() system call and its return type is (void *).its declaration is void * shmat(shmid,void * addr,int flag);

	shmid=shmget(KEY,512,IPC_CREAT|0666);//its declaration is INT SMGET(KEY_T KEY,SIZE_T SIZE, INT FLAG);

	if(shmid<0)
	{
		printf("Failed to create\n");
		exit(0);
	}
	ptr=shmat(shmid,NULL,0);//it returns the virtual address // for writing the data into shared memory region, we need to attach the sharedmemory into physical memory(it will create in freely available physical frames in between stack and heap).this system call will gives us virtual address which is stored in a ptr.

	printf("Shared memory address:%p\n",ptr);
	ptr[0]='\0';//acts as blocking call..........// this process will be in block state for this statement, until another process writes the data. we are just putting this process into block state(for our understanding process);


	while(ptr[0]=='\0')
		sleep(1);
	printf("%s\n",ptr);





	ret=shmdt(ptr);
}
	
