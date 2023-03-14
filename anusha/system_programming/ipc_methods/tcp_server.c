//.....................................TCP SERVER.....................................

#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int sockfd,newsockfd,client_size,ret;
	char buf[256];
	struct sockaddr_in serv,client;
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	//memset(&serv,0,sizeof(struct sockadd_in));
	
	bzero(&serv,sizeof(struct sockaddr_in));

	serv.sin_family=AF_INET;
	serv.sin_port=htons(5326);
	serv.sin_addr.s_addr=INADDR_ANY;

	ret=bind(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	if(ret<0)
	{
		printf("bind value:%d\n",ret);
		exit(3);
	}

	listen(sockfd,5);
	client_size=sizeof(client);

	newsockfd=accept(sockfd,(struct sockaddr*)&client,&client_size);
	if(newsockfd==-1)
	{
		printf("failed to accept\n");
		exit(2);
	}
	
	while(1)
	{
		ret=read(newsockfd,buf,256);
		if(ret<0)
		{
			printf("Failed to read the data:");
			exit(1);
		}
		write(1,buf,ret);

		printf("\n");
		printf("server:");

	        scanf("%[^\n]s",buf);

		 __fpurge(stdin);
       		 ret=send(newsockfd,buf,strlen(buf),0);
		 if(ret<0)
		 {
			 printf("Failed to write:");
			 exit(2);
		}

	
	//	close(newsockfd);
	//	close(sockfd);
	}
}



