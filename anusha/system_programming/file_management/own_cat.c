//wap to implement the own cat command

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs are insufficient\n");
		exit(1);
	}
	int fd,ret;
	char buff[100];
	fd=open(argv[1],O_RDONLY);// inputs are given at runtime....to open the file ...passing argument1 (cmd) and perfoming read operation
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(2);
	}
	ret=read(fd,buff,99);//if the buf[10],it performs 1 iteration and read only 9 bytes
//	while(ret=read(fd,buff,99))//it performs until the cursor reaches to 99
//	{
		if(ret<0)
		{
			printf("Failed to read the file\n");
			exit(3);
		}
		buff[ret]='\0';
		printf("%s\n",buff);//printing the buffer value 
//	}
	close(fd);//closing the fd by close command
}
		

