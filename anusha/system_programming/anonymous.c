//.....................................ANONYMOUS....................................

#include<unistd.h>
#include<sys/mman.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

void main()
{
	int *ptr;
	#ifdef USE_MAP_ANON
		ptr=mmap(NULL,sizeof(int),PROT_READ|PROTWRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
		
	#endif
		int fd=open("/dev/zero",O_RDWR);
		ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

		int pid=fork();
		if(pid>0)
		{
			sleep(2);
			printf("Parent process:%d\n",*ptr);
			exit(0);
		}
		else
		{
			*ptr=4;
			printf("child process:%d\n",*ptr);
			exit(1);
		}
}
