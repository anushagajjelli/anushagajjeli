//wap to perform the message queue 
//..........................................CLIENT...............................



#include<stdio_ext.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
//#include<sys/types.h
#define MSG_TYPE 1
#define KEY     0x1998860

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

	msgid=msgget(KEY,0);
	printf("Return value of msgid:%d\n",msgid);
	while(1)
	{

	message.msgtype=MSG_TYPE;
	message.pid=getpid();
	
	printf("Enter the string in client:");
	__fpurge(stdin);
	scanf("%[^\n]s",message.buf);
	
	msgsnd(msgid,&message,2*sizeof(long)+strlen(message.buf)+1,0);
	
	msgrcv(msgid,buf,sizeof(message.buf),MSG_TYPE,0);
	printf("DATA RECEIVED AT CLIENT:%s\n",buf+2*sizeof(long)); 
	
	}
}
