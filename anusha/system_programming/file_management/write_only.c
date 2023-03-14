//wap to perform the write only operation
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	char buf[30]="Anusha Gajjelli";
	char rbuf[30];
	int fd,ret;
	fd=open("samplee.txt",O_RDWR);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret=write(fd,buf,strlen(buf));
	printf("ret value:%d\n",ret);
//	sleep(20);
	ret=read(fd,rbuf,30);
	printf("return value:%d\n",ret);
	rbuf[ret]='\0';
	printf("String:%s\n",rbuf);
	close(fd);
}
