//....ap a client to server program to perform below bank operations.........................................
//......................USING TCP PROTOCOL..............................

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>


void main()
{
	int fd,fd1,ret,ret1;
	 fd=mkdir("database",0777);
        
	if(fd<0)
	{
		 open("database",O_RDWR,0); 
		 chdir("database");
	 	fd1=mkdir("userid",0777);
		open("userid",O_RDWR,0);
		chdir("userid");
		open("profile.txt",O_CREAT|O_RDWR,0664);
		open("transaction.txt",O_CREAT|O_RDWR,0664);
	}
	
	open("database",O_RDWR,0); 
	chdir("database");
	fd1=mkdir("userid",0777);
	open("userid",O_RDWR,0);
	chdir("userid");
	open("profile.txt",O_CREAT|O_RDWR,0664);
	open("transaction.txt",O_CREAT|O_RDWR,0664);
	
	
	
	

	
	
}



void socket()
{
	int sockfd,newsockfd,client_size,ret;

	char rbuf[256];
	struct sockaddr_in serv,client;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	printf("socket return value:%d\n",socket);
	
	bzero(&serv,sizeof(struct sockaddr_in));
	
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5555);
	serv.sin_addr.s_addr=INADDR_ANY;

	ret=bind(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	if(ret<0)
	{
		printf("bind value:%d\n",ret);
		exit(1);
	}
	
	listen(sockfd,5);
	client_size=sizeof(client);

	newsockfd=accept(sockfd,(struct sockaddr*)&client,&client_size);
	if(newsockfd<0)
	{
		printf("Failed to accept the client request:");
		exit(2);
	}
	
























	
