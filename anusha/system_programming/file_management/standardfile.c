//PROGRAM TO VERIFY THE STANDARD I/O FILE DISCRIPTORS
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int fd,fd1,fd2,fd3;
	char buf[30]="this is monday";

	fd=open("hello.txt",O_RDWR);
	perror("open");
	if(fd<2)
	{
		printf("failed to open\n");
		exit(1);

	}

	printf("return valueof open= %d\n ",fd);

	fd3=read(0,buf,12);//HERE STDIN(which we used as a readig the input),it is used with read().it acts  as a blocking call.
	perror("read");

          
        fd2=write(1,buf,20);//it shows the string in the terminal
	perror("write");

	fd1=write(fd,buf,29);//overwrites the data
	perror("write");
	printf("%s\n",buf);
}





