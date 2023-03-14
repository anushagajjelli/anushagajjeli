#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define MSG_TYPE 1
#define key 0x1978998

struct def
{
	long msgtype;
	long pid;
	char buf[100];
}suraj;


void main()
{
	int msgid;
	
	msgid=msgget(key,0);
	printf("msgid=%d\n",msgid);

	suraj.msgtype=MSG_TYPE;
	suraj.pid=getpid();
	strcpy(suraj.buf,"this is suraj from server");//message to be sent


	msgsnd(msgid,&suraj,sizeof(suraj),0);
}
