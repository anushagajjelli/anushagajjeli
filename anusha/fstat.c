#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
void main()
{
	struct stat buf;
	int fd , x,y;
	fd = open("/home/engineer/Desktop/kishore_cp/kishorecp/system_programing/stat1.c",O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open the file\n");
		exit(1);
	}
	 x = fstat(fd,&buf);
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
