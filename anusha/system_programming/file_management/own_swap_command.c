//wap to implement swap command

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main(int argc,char* argv[])
{
	char buf[30];
	int fd,fd1,fd2,fd3,ret,ret1,ret2,ret3;
	fd=open(argv[1],O_RDWR)
	if(fd<0)
	{
		printf("Failed to open file\n");
		exit(1);
	}
	fd1=open(argv[2],O_RDWR)
	if(fd1<0)
	{
		printf("Failed to open file\n");
		exit(2);
	}
	ret=read(
