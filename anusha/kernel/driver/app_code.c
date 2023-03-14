//wap to perform the driver code.......it is a application code

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main()
{
	char buf[100];
	char rbuf[100];
	int ret,fd;
	fd=open("/dev/mychar",O_RDWR);
	if(fd<0)
	{
		printf("Failed to establish the communication\n");
		exit(0);
	}

	printf("Enter the input\n");
	scanf("%s",buf);

	ret=write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("Fail to perform the write operation\n");
		exit(1);
	}

	ret=read(fd,rbuf,sizeof(rbuf));
	if(ret<0)
	{
		printf("Failed to reaf the data\n");
		exit(2);
	}
	printf("seashore\n");

	printf("return value of write operation:%d\n",ret);
}

