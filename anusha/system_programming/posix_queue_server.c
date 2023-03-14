//...............................wap to perform the posix message queue.........................
//.......................................SERVER...........................................

#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>

/*#define flag 0
#define maxmsg 10
#define maxmsgsize 8192
#define curmsgs 1*/

void main()
{
	mqd_t mqid;
	char buf[8192];
	int prior=1;
	long int len;
	
	struct mq_attr chinnu;

	chinnu.mq_flags=0;
	chinnu.mq_maxmsg=10;
	chinnu.mq_msgsize=8192;
	chinnu.mq_curmsgs=0;

	mqid=mq_open("/anu",O_CREAT|O_RDWR,0660,&chinnu);

	if(mqid<0)
	{
		printf("failed to create\n");
		exit(1);
	}

	printf("mqid=%d\n",mqid);
	while(1)
	{

       mq_receive(mqid,buf,sizeof(buf),&prior);
       printf("Received:%s\n",buf);
	__fpurge(stdin);
       scanf("%[^\n]s",buf);
        len=strlen(buf);
        mq_send(mqid,buf,len+1,prior);
	}

}


