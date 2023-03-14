                
                         //SERVER
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdlib.h>

#define key 0x1978998
#define MSG_TYPE 1
struct def
{
        long msgtype;
        long pid;
        char buf[100];//message will recieve in this
}suraj;


void main()
{
	int msgid;
	
	
	msgid=msgget(key,0660|IPC_CREAT);
	printf("msgid=%d\n",msgid);


	msgrcv(msgid,&suraj,sizeof(suraj),1,0);
	printf("data recieved is :");
	printf("%s\n",suraj.buf);

	//msgctl(msgid,IPC_STAT,&suraj);


      




}
