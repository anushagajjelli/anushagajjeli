#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int fd,ret,nfd;
	char buf[20];
	fd=open("samplee.txt",O_RDWR);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret=read(fd,buf,5);
	buf[ret]='\0';
	printf("%s",buf);
	nfd=creat("sample1.txt",0664);
	ret=write(nfd,"hi",strlen("hi"));
	if(ret<0)
	{
		printf("Failed to write\n");
		exit(2);
	}
	ret=read(fd,buf,5);
	if(ret<0)
	{
		printf("Failed to read\n");
		exit(3);
	}
	ret=write(fd,"hello",5);
	
}

