#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
void main()
{
	char buf[30]="Good morning";
	int fd,ret,a;
	close(0);//closing the stdin i.e. scanf function nothing can be read
//	close(1);//closing the stdout i.e. printf() ..so nothing will be printed in terminal screen
	printf("Enter the data:");
	scanf("%d",&a);
	/*fd=open("sample.txt",O_RDWR);
	ret=read(fd,buf,12);
	printf("%d",ret);*/
}
