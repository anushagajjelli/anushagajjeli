//...............................Shared memory...................................
//...............................CLIENT...........................................

#include<stdio_ext.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

#define KEY 0x1998800 
void main()
{
	int shmid,ret;
	char* ptr;
	shmid=shmget(KEY,512,0);//to allocate 512bytes in shared memory
	printf("Return alue:%d\n",shmid);
	if(shmid<0)
	{
		printf("Faild to create memory\n");
		exit(2);
	}
	ptr=shmat(shmid,NULL,0);//attach the counter to the physical address
	printf("shmatter ->%p\n",ptr);

	if(ptr==NULL)
	{
		printf("Faild to create virtual addres\n");
		exit(2);
	}

	printf("Enter the string:");
	scanf("%[^\n]s",ptr);

	ret=shmdt(ptr);//deattach the process
	if(ret<0)
	{
		printf("Faild to close\n");
		exit(2);
	}



	
}
