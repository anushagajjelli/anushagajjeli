//wap to perform readonly 

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
void main()
{
	int fd1,fd2,ret1,ret2;
	char buf1[10];
	char buf2[10];
	fd1=open("samplee.txt",O_RDONLY);
	printf("FD value:%d\n",fd1);
	if(fd1<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret1=read(fd1,buf1,9);
	printf("ret value:%d\n",ret1);
	if(ret1<0)
	{
		printf("Failed to read the file\n");
		exit(2);
	}
	buf1[ret1]='\0';
	printf("Buffer1:%s\n",buf1);

	fd2=open("samplee.txt",O_RDONLY);
	printf("FD value:%d\n",fd2);
	if(fd2<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret2=read(fd2,buf2,6);
	printf("ret value:%d\n",ret2);
	if(ret2<0)
	{
		printf("Failed to read the file\n");
		exit(2);
	}
	buf2[ret2]='\0';
	printf("Buffer1:%s\n",buf2);
	close(fd1);
	close(fd2);
}
