//wap to perform the read operation

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	int fd,ret;
	char buf[10];
	fd=open("samplee.txt",O_RDONLY);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	while(ret=read(fd,buf,6))
	{
		if(ret<0)
		{
			printf("Failed to read\n");
			exit(2);
		}
		buf[ret]='\0';
		printf("string:%s\n",buf);
	}
}
