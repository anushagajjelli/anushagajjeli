//wap to perform the named pipes...........information send from client to server.........
//......................one way communication..................................
//...........................client to server....................................
//............................uppercase to lower........................

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
void main()
{
	int ret,fd,fd1;
	char wbuf[20];
	char rbuf[50];
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



	printf("\nEnter the message to client:");
	scanf("%[^\n]s",wbuf);

	fd1=open("clientfifo",O_WRONLY);
	if(fd1<0)
	{
		printf("Failed to open the file\n");
		exit(5);
	}

	else
	{


	 	int i;
     		   for(i=0;wbuf[i]!='\0';i++)
       		   {
               		 if(wbuf[i]>='A' && wbuf[i]<='Z')
                       		 wbuf[i]=wbuf[i]+32;
             	         else if(wbuf[i]>='a' && wbuf[i]<='z')
                      		  wbuf[i]=wbuf[i]-32;
       		   }


		ret=write(fd1,wbuf,strlen(wbuf));
		printf("ret value-%d\n",ret);
		printf("%s",wbuf);
		if(ret<0)
		{
			printf("failed to write\n");
			exit(6);
		}
	}
	close(fd);
	close(fd1);

}

