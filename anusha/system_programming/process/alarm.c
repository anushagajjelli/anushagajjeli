//wap to perform the alarm

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void myhandler(int);
void main()
{
        int i=0;
       // signal(14,myhandler);//SIGALRM
	alarm(5);
        while(i<2)
        {
               // sleep(1);
                printf("inifinty loop %d\n",i);
                i++;
        
	}
	printf("%d\n",alarm(2));
}

/*void myhandler(int signo)
{
        printf("%d\n",signo);
}*/



