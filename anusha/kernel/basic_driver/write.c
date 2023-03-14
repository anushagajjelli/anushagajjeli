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
	fd=open("/dev/mymodule",O_WRONLY);
	if(fd<0)
	{
		printf("Failed to establish the communication\n");
		exit(0);
	}

	printf("Enter the input\n");
	scanf("%s",buf);

	ret=write(fd,buf,strlen(buf));
	printf("return value of write:%d\n",ret);
	if(ret<0)
	{
		printf("Fail to perform the write operation\n");
		exit(1);
	}
	
//	buf[ret]='\0';
	//printf("return value of write operation:%d\n",ret);
	printf("%s\n",buf);

/*	ret=lseek(fd,-5,SEEK_SET);
		printf("return value :%d\n",ret);

	ret=read(fd,rbuf,strlen(rbuf));
	if(ret<0)
	{
		printf("Failed to read\n");
		exit(2);
	}
	buf[ret]='\0';*/
	close(fd);
}

