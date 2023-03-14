//wap to create the own cat command using mmap 

#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
void main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs\n");
		exit(0);
	}
	
	struct stat buf;
	char* ptr;
	int fd;
	fd=open(argv[1],O_RDWR);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	fstat(fd,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	write(1,ptr,buf.st_size);
	munmap(ptr,buf.st_size);
}

