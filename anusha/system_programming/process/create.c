//wap to implement the create system call 

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char buf[50]="Anusha is a good girl";
	int fd,fd1,ret,ret2,ret1;
	fd=open("sample12.txt",O_RDWR|O_CREAT|O_APPEND,0665);
	printf("fd value-%d\n",fd);
	
	ret=write(fd,buf,50);
	printf("write return value:%d\n",ret);
	printf("%s\n",buf);



	
       ret2=lseek(fd,-48,SEEK_CUR);
       printf("return value of lseek=%d\n",ret2);
       printf("%s\n",buf);

	ret1=read(fd,buf,6);
	printf("Return value:%d\n",ret1);
	buf[ret1]='\0';
	printf("String:%s\n",buf);
	
}

