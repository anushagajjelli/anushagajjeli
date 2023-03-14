//wap to perform the fd table operation ...how the fd table stores the address of the file objects ....by using their return values

#include<stdio.h>
#include<fcntl.h>
void main()
{
	int fd,fd2,fd3,fd4;
	fd=open("abort1.txt",O_RDONLY,0444);
	fd2=open("abort1.txt",	O_RDONLY,0666);

	printf("fd return value:%p-%d\n",&fd,fd);
	printf("fd2 value:%p-%d\n",&fd2,fd2);
	close(fd);
	fd3=open("abort1.txt",O_RDONLY,0555);
	printf("fd3 return value:%p-%d\n",&fd3,fd3);
	fd4=open("abort1.txt",O_RDONLY,0655);
	printf("fd4 return value : %p-%d\n",&fd4,fd4);
}
