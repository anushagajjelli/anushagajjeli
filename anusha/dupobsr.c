#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	char buf[100];
	int fd,fd1,fd2,fd3,fd4;

	fd=open("hello.txt",O_RDWR);
	perror("open");
        printf("return vaue =%d\n",fd);

	close(fd);

	fd1=dup(fd);
	perror("dup");
	printf("%d\n",fd1);
}

