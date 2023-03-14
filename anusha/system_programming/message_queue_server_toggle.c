//wap to perform the message queue from client to server
//.........................................SERVER.................................
#include<stdio_ext.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define MSG_TYPE 1
#define KEY      0x1998860

struct msg
{
	long msgtype;
	long pid;
	char buf[100];
}message;

void main()
{
	int msgid,i;
	char buf[100];	
	msgid=msgget(KEY,IPC_CREAT|0640);

	if(msgid<0)
	{
		printf("Failed to create\n");
		exit(2);
	}
//	while(1)
//
//	{
	printf("msgid return value=%d\n",msgid);

	msgrcv(msgid,buf,sizeof(buf),MSG_TYPE,0);
	
        

        printf("Data received:%s\n",buf+(2*sizeof(long)));
	
	message.msgtype=MSG_TYPE;
        message.pid=getpid();



	printf("Enter the message:");
        scanf("%[^\n]s",message.buf);
        
        
        for(i=0;message.buf[i]!='\0';i++)
        {
                if(message.buf[i]>='A' && message.buf[i]<='Z')
                        message.buf[i]=message.buf[i]+32;
                else if(message.buf[i]>='a' && message.buf[i]<='z')
                        message.buf[i]=message.buf[i]-32;
        }

	//printf("%s\n",message.buf);
	
	msgsnd(msgid,&message,2*sizeof(long)+strlen(message.buf)+1,0);
	
	//msgsnd(msgid,&message,2*sizeof(long)+strlen(message.buf)+1,0);
//	}
}



