//wap to create the own stat command

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
void main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs\n");
		exit(1);
	}

	struct stat buf;
//	int x;
	stat(argv[1],&buf);
/*	if(x<0)
	{
		printf("Fsiled to read the data\n");
		exit(2);
	}*/

	printf("Id od device containing file : %ld\n",buf.st_dev);
	printf("Inode number : %ld\n",buf.st_ino);
	printf("File type and mode : %x\n",buf.st_mode);
	printf("Number of hard links : %ld\n",buf.st_nlink);
	printf("User Id of owner : %d\n",buf.st_uid);
	printf("Group ID of owner: %d\n",buf.st_gid);
}


