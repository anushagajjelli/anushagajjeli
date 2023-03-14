//wap to perfoem the read operation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	char buf[100];
	int fd,ret;
	fd=open("/dev/mymodule",O_RDWR);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	ret=read(fd,buf,sizeof(buf));
	if(ret<0)
	{
		printf("Fail to perform the write operation\n");
		exit(2);
	}

	printf("Return value of read operation:%d\n",ret);
//	buf[ret]='\0';
	printf("%s\n",buf);
	close(fd);
}
