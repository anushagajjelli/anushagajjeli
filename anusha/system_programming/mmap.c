//wap to check the memory mapping

#include<sys/mman.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

void main()
{
	struct stat buf;
	int fd;
	char *ptr;
	fd=open("file.txt",O_RDWR);
	if(fd<0)
	{
		write(1,"Failed to open the file\n",1000);
		exit(0);
	}
	fstat(fd,&buf);
	ptr=mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	write(1,ptr,buf.st_size);
	munmap(ptr,buf.st_size);
}

