//wap to perform seek operation

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	char buf[30];
	char rbuf[30]="Ankitha";
	int fd,ret,ret1,ret2;
	fd=open("samplee.txt",O_RDWR);
	if(fd<2)
	{
		printf("Failed to open the file\n");
		exit(1);
	}
	printf("fd value:%d\n",fd);
	ret=lseek(fd,5,SEEK_SET);//cursor position will move from starting position to 5th position
	printf("Cur set ret-%d\n",ret);

	ret=lseek(fd,-5,SEEK_CUR);
	printf("seek cur-%d\n",ret);
	
//	ret=lseek(fd,0,SEEK_END);
//	printf("seek end:%d\n",ret);

	ret1=read(fd,buf,5);
	printf("ret1-%d\n",ret1);
	if(ret1<0)
	{
		printf("Failed to read\n");
		exit(2);
	}
	buf[ret1]='\0';
	printf("string1:%s",buf);

	ret2=write(fd,rbuf,5);
	printf("ret2-%d\n",ret2);
	rbuf[ret2]='\0';
	printf("String-%s\n",rbuf);

}

