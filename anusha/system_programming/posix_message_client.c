//.......................wap to perform the posix message queue...........................
//.....................................CLIENT.........................................

#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<mqueue.h>

void main()
{
	mqd_t mqid;
	int prior=1;
	long int len;
	char buf[8192];
	mqid=mq_open("/anu",O_RDWR);
	while(1)
	{
		__fpurge(stdin);
	scanf("%[^\n]s",buf);
	len=strlen(buf);
	mq_send(mqid,buf,len+1,prior);

	 mq_receive(mqid,buf,sizeof(buf),&prior);
         printf("Received data:%s\n",buf);
	}

}
