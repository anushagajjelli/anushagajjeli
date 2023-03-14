//............................wap to perform client to server communication..................

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	int ret,fd,fd1;
	char rbuf[20];
//	char wbuf[30]="HELLO moschip";

	char wbuf[30];
	printf("Enter the message to server:");
	scanf("%[^\n]s",wbuf);
	fd=open("serverfifo",O_WRONLY);
	printf("fd value-%d\n",fd);
	if(fd<0)
	{
		printf("Failed to open\n");
		exit(0);
	}

	 int i;
        for(i=0;wbuf[i]!='\0';i++)
        {
                if(wbuf[i]>='A' && wbuf[i]<='Z')
                        wbuf[i]=wbuf[i]+32;
                else if(wbuf[i]>='a' && wbuf[i]<='z')
                        wbuf[i]=wbuf[i]-32;
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
		ret=mkfifo("clientfifo",0660);
		if(ret<0)
		{
			printf("Failed to create the file\n");
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

	write(1,rbuf,ret);
	close(fd1);


	close(fd);
}
