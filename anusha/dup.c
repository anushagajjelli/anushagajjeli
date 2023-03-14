#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int fd,fd1,fd2,fd3,fd4,fd5,fd6;
	char buf[100];

	fd=open("hello.txt",O_RDWR);
	perror("open");
	if(fd<2)
	{
		printf("failed to open\n");
		exit(1);
	}
	printf("open return value=%d\n",fd);

	fd1=dup(fd);//it will  not create a new file object but update the fd table which is free available.
	printf("dup return value=%d\n",fd1);

        fd3=write(1,"hi this  is suraj",strlen("hi this is suraj"));
	perror("write");


	fd4=write(fd1,"bye",strlen("bye"));
	perror("write");

	fd5=dup(3);
        perror("dup");
	printf("2nd duplicate value=%d\n",fd5);

         
	fd6=write(fd,"good morning",strlen("good morning"));
	perror("write");



	fd2=read(fd,buf,12);
	buf[fd2]='\0';
	printf("%s\n",buf);


	



}
