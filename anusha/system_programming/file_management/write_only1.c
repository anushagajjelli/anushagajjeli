//wap to perform the write only operation
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
        char buf[30]="Anusha Gajjelli";
        char rbuf[30];
        int fd,ret;
        fd=open("samplee.txt",O_RDWR);
        if(fd<0)
        {
                printf("Failed to open the file\n");
                exit(1);
        }
        ret=read(fd,rbuf,15);
	printf("%d\n",ret);
	ret=write(fd,buf,16);
	buf[ret]='\0';
	printf("write=%d\n",ret);
	printf("%s",buf);

}
                                                                                                    
