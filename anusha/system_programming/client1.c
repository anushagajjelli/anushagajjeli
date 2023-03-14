
//............................wap to perform client to server communication..................
//........................................client...................................

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio_ext.h>
#include<stdlib.h>
void main()
{
	int ret,fd,fd1;
	char rbuf[20];
//	char wbuf[30]="request";

	char wbuf[30];
	while(1)
	{
		printf("\n");
	//printf("\nEnter the message to server:");
	__fpurge(stdin);
	scanf("%[^\n]s",wbuf);
	fd=open("serverfifo",O_WRONLY);
	if(fd<0)
	{
		printf("Failed to open\n");
		exit(0);
	}
	ret=write(fd,wbuf,strlen(wbuf));
	if(ret<0)
	{
		printf("Failed to write\n");
		exit(1);
	}


	  fd1=open("clientfifo",O_RDONLY);
        if(fd1<0)
        {
                ret=mkfifo("clientfifo",0777);
                if(ret<0)
                {
                        printf("Failed to create file object\n");
                        exit(2);
                }
                else
                {
                        fd1=open("clientfifo",O_RDONLY);
                        if(fd1<0)
                        {
                                printf("Failed to open\n");
                                exit(3);
                        }
                }

        }
        ret=read(fd1,rbuf,20);
        if(ret<0)
        {
                printf("Failed to perform the read operation\n");
                exit(4);
        }
        ret=write(1,rbuf,ret);
        if(ret<0)
        {
                printf("Failed to perform write operation\n");
                exit(5);
        }
        close(fd);

	close(fd1);
	}
}
