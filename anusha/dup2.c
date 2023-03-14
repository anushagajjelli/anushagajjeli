#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
 
void main()
{
	int fd,fd1,fd2,fd3,fd4;
	char buf[100];

	fd=open("hello.text",O_RDWR);
	perror("open");
	printf("return value of open=%d\n",fd);


	fd2=creat("bye.txt",0777);
	perror("creat");
	printf("creat return value=%d\n",fd2);

	fd3=write(fd2,"hello good morning",strlen("hello good morning"));
	perror("write");
	printf("%s\n",buf);



	fd1=dup2(fd,fd2);
	perror("dup2");
	printf("return value of dup,fd1=%d\n",fd1);


}
