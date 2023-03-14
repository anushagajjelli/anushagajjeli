//wap to perform the own copy command

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs\n");
		exit(1);
	}
	char buf[30];
	int fd,ret,fd1,ret2;

	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		printf("Failed to open the file\n");
		exit(2);
	}

	fd1=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0777);
	if(fd1<0)
	{
		printf("Failed to open the 2nd file\n");
		exit(3);
	}

/*	ret=read(fd,buf,29);
	if(ret<0)
	{
		printf("Failed to read the data\n");
		exit(3);
	}
	buf[ret]='\0';

	fd1=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0777);
	if(fd1<0)
	{
		printf("Failed to open the 2nd file\n");
		exit(4);
	}
	ret2=write(fd1,buf,29);
	buf[ret2]='\0';
	printf("Copied element-%s\n",buf);*/



	while(ret=read(fd,buf,29))
	{
	
		if(ret<0)
		{
			printf("Failed to read the data\n");
			exit(3);
		}
	
		ret2=write(fd1,buf,ret);
		if(ret2<0)
		{
			printf("failed to read data\n");
			exit(4);
		}
	}
	close(fd);
	close(fd1);
}


