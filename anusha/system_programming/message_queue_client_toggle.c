//wap to perform the message queues by using client to server
//................................CLIENT.................................


#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

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
	//struct msg message;
	int msgid,i;
	char buf[100];
	msgid=msgget(KEY,0);
	printf("Return value of msgid-%d\n",msgid);

	message.msgtype=MSG_TYPE;
	message.pid=getpid();
	//strcpy(message.buf,"ANUSHA");
	//msgsnd(msgid,&message(2*sizeof(long int))+strlen(message.buf)+1,0);
	

	printf("Enter the message:");
	scanf("%[^\n]s",message.buf);
	
	for(i=0;message.buf[i]!='\0';i++)
	{
	
		  if(message.buf[i]>='A' && message.buf[i]<='Z')
                        message.buf[i]=message.buf[i]+32;
                else if(message.buf[i]>='a' && message.buf[i]<='z')
                        message.buf[i]=message.buf[i]-32;
        }

	msgsnd(msgid,&message,2*sizeof(long)+strlen(message.buf)+1,0);
	
	 //msgsnd(msqid,&message,((2*sizeof(long))+(strlen("hello")+1)),0);
	
		
	msgrcv(msgid,buf,sizeof(message.buf),MSG_TYPE,0);
	printf("Data received from server:%s\n",buf+2*sizeof(long));
	//printf("%s\n",buf+2*sizeof(long));
		

}
