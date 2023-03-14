//program to  TOGGLE THE DATA 

#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
	int r,r1;

	int fd[2],fd1[2];
        char buf[100]="my name is jerom suraj";
	r=pipe(fd);
	r1=pipe(fd1);
	if( r!=0)
	{
		printf("failed to send data\n");
		exit(1);
	}
	printf("pipe1 return value=%d\n",r);
	printf("pipe2 return value=%d\n",r1);


	pid_t pid=fork();
	printf("pid return value=%d\n",pid);
	
	if(pid<0)
	{
		printf("failed to create child process\n");
		exit(1);
	}

        else if(pid>0)
	{
		int i,j;

		close(fd[0]);
		close(fd1[1]);

		i=write(fd[1],buf,100);
		perror("write");
                if(i<2)
		{
			printf("failed t0 write\n");
			exit(1);
		}
		printf("write return value=%d\n",i);
		close(fd[1]);

		j=read(fd1[0],buf,100);
		printf("parent process\n");
		write(1,buf,100);

		close(fd1[0]);

	}



	else
	{
		int i,j,k=0;

		close(fd[1]);

		i=read(fd[0],buf,100);
		printf("child process\n");
	        write(1,buf,100);

		close(fd[0]);

                
		for(j=0;buf[j]!='\0';j++)
		{
			if((buf[j]>=97)&&(buf[j]<=122))
			{
				buf[j]=buf[j]-32;
			}
			else if((buf[j]>=65)&&(buf[j]<=90))
			{
				buf[j]=buf[j]+32;
			}
		}
		close(fd1[0]);
		write(fd1[1],buf,strlen(buf));
		close(fd1[1]);

	        
	}
}







