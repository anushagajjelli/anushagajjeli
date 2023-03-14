#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int fd,fd1,fd2,fd3,fd4;
	

	fd=open("sample1.c",O_RDWR);
	printf("fd=%d\n",fd);

	fd1=open("sample2.c",O_RDWR);
	printf("fd1=%d\n",fd1);


	fd2=dup2(fd,fd1);
	printf("fd2=%d\n",fd2);



}

