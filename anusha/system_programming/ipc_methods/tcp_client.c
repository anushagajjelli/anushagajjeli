//.............................TCP CLIENT...........................

#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>

void main()
{
	int sockfd,ret;
	struct sockaddr_in serv;
	char buf[256];
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	bzero(&serv,sizeof(serv));

	serv.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5326);
	connect(sockfd,(struct sockaddr*)&serv,sizeof(serv));
	//	printf("Failed to connect\n");

	while(1)
	{
		printf("Enter string:");
		scanf("%[^\n]s",buf);

		__fpurge(stdin);

		ret=send(sockfd,buf,strlen(buf),0);
		if(ret<0)
		{
			printf("Failed to send:");
			exit(0);
		}
		
		//recv(sockfd,buf,256,0);
		ret=read(sockfd,buf,256);
		printf("return value:%d\n",ret);

		write(1,buf,ret);

		//close(sockfd);
	}
}
