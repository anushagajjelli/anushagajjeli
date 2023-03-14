#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
 
void main()
{
	int fd,fd1,fd2,fd3;

	fd1=dup(fd);
	perror("dup");
	printf("%d\n",fd1);

	close(fd1);


	fd=open("hello.txt",O_RDWR);
	perror("open");
	printf("return value of open=%d\n",fd);
}
