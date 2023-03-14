#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argv,char *argc[],char *env[])
{
	int i,j,k,m,fd,ret,num,ret1,sz,sz1;
	char *buff;
	char buf[100];
	if(argv>=2)
	{
		for(i=1;i<argv;i++)
		{
			if((strcmp(argc[2],"--help"))==0)
			{
				printf("Help\n");
				exit(0);
			}
			else if(argc[i][0]=='/')
			{
				for(k=0;argc[i][k]!='\0';k++)
					buf[k]=argc[i][k];
			}
			else
			{
				for(j=10;j<20;j++)
				{
					if((env[j][0]=='P')&&(env[j][1]=='W')&&(env[j][2]=='D')&&(env[j][3]=='='))
					{
						for(k=0,m=4;env[j][m]!='\0';k++,m++)
							buf[k]=env[j][m];
						buf[k]='/';
						strcat(buf,argc[i]);
						printf("%s\n",buf);
						break;
					}
				}
			}
			fd=open(buf,O_RDONLY);
			if(fd<0)
			{
				printf("File dosent exit\n");
				continue;
			}
			sz=lseek(fd,0,SEEK_END);
			if(sz<0)
			{
				printf("Failed to get size\n");
				continue;
			}
			buff=(char*)malloc(sz*sizeof(char));
			if(buff==NULL)
			{
				printf("Failed to allocate the memory in the heap\n");
				continue;
			}
			sz1=lseek(fd,0,SEEK_SET);
			if(sz1<0)
			{
				printf("Failed to reset the size\n");
				continue;
			}
			ret=read(fd,buff,sz);
			if(ret<0)
			{
				printf("failed to read\n");
				continue;
			}
			printf("%s\n",buff);
			free(buff);
			bzero(&buf,sizeof(buf));
			close(fd);
		}
	}
	else
		printf("Less inputs\n");
}
