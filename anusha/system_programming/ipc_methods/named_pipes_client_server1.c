//wap to perform the named pipes...........information send from client to server and server to client.........
//......................two way communication..................................
//...........................clent to server and vice-versa....................................
//......................................server......................................

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdio_ext.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	int ret,fd,fd1;
	char wbuf[20];
	char rbuf[50];
	while(1)
	{
	fd=open("serverfifo",O_RDONLY);
	if(fd<0)
	{
		ret=mkfifo("serverfifo",0777);
		if(ret<0)
		{
			printf("Failed to create file object\n");
			exit(0);
		}
		else
		{
			fd=open("serverfifo",O_RDONLY);
			if(fd<0)
			{
				printf("Failed to open\n");
				exit(1);
			}
		}

	}
	ret=read(fd,rbuf,20);
	if(ret<0)
	{
		printf("Failed to perform the read operation\n");
		exit(3);
	}
	ret=write(1,rbuf,ret);
	if(ret<0)
	{
		printf("Failed to perform write operation\n");
		exit(4);
	}
	close(fd);

	//printf("Enter the message to client\n");
	 printf("\n");
	 __fpurge(stdin);
        scanf("%[^\n]s",wbuf);
        fd1=open("clientfifo",O_WRONLY);
        if(fd1<0)
        {
                printf("Failed to open\n");
                exit(0);
        }
        ret=write(fd1,wbuf,strlen(wbuf));
        if(ret<0)
        {
                printf("Failed to write\n");
                exit(5);
        }

	close(fd1);
	}

}

