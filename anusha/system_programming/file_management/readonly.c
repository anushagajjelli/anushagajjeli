//wap to perform the readonly operation and verify

#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	char buf[100];
	int fd,ret;
	fd=open("sample1.c",O_RDONLY);
	printf("Fd return value:%d\n",fd);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret=read(fd,buf,6);
	printf("ret:%d\n",ret);
	buf[ret]='\0';
	printf("buffer-%s\n",buf);
	ret=read(fd,buf,9);
	printf("%d\n",ret);
	buf[ret]='\0';
	printf("buffer-%s\n",buf);

	close(fd);
}
