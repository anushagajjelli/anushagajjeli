//wap to perform the standard input and output functions 

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int fd,fd1,fd2,fd3;
	char buf[30]="This is Tuesday";

	fd=open("samplee.txt",O_RDWR);
	if(fd<0)
	{
		printf("Failed to open\n");
		exit(1);
	}

	printf("Return value of open-%d\n",fd);

	fd1=read(0,buf,12);//it reads till 7letters

	fd2=write(1,buf,15);
	perror("write");

	fd3=write(fd,buf,20);
	printf("%s\n",buf);

}
