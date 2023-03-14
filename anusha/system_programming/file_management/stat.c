#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
void main(int n, char *arg[])
{
	struct stat buf;
	int x ;
	if(n>2 || n<=1)
	{
		printf("enter the valid input\n");
		printf("stat < file name along with path >\n");
		exit(2);
	}
	x = stat(arg[1],&buf);
	if( x < 0)
	{
		printf("failed to read the details\n");
		exit(1);
	}
	printf("ID of device containing file : %ld\n",buf.st_dev);
	printf("Inode number : %ld\n",buf.st_ino);
	printf("File type and Mode : %x\n",buf.st_mode);
	printf("Number od hard links : %ld\n",buf.st_nlink);
	printf("User ID of owner : %d\n",buf.st_uid);
	printf("Group ID of owner : %d\n",buf.st_gid);
}
