#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs\n");
		exit(0);
	}
	int fd,fd1;
	char *ptr,*ptr1;
	struct stat buf;
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	fstat(fd,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ,MAP_SHARED,fd,0);
	
	fd1=open(argv[2],O_CREAT|O_RDWR);
	if(fd1<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	fstat(fd1,&buf);
	ftruncate(fd1,buf.st_size);
	ptr1=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
	
	memcpy(ptr1,ptr,buf.st_size);
//	write(1,ptr1,buf.st_size);
//	munmap(ptr1,buf.st_size);
}
	
	
	
	
