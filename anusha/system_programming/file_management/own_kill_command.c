//wap to perform the own kill command

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
void main(int argc,char* argv[])
{
	if(argc<2)
	{
		printf("Invalid inputs\n");
		exit(1);
	}
	if(argv[1][0]!='-')
	{
		printf("Entered invalid inputs\n");
		exit(2);
	}
	char buf[30];
	char temp;
	int i=0,ret,k,j,sum=0,fd;
	int *ptr;
	ptr=(int*)malloc((argc-1)*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(3);
	}
	for(i=1;i<argc;i++)
	{
		k=argv[i][j];
		for(j=0;argv[i][j]!='\0';j++)
		{
			if(argv[i][j]>='0'&&argv[i][j]<='9')
			{
				temp=argv[i][j]-48;
				sum=sum*10+temp;
			}
		
		}
		sum=k;

	}
	k=argv[i][j];
	fd=open(argv[1],argv[2]);
	
}
