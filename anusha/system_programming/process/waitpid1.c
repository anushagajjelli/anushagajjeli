#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
        int w;
        int status=0;
        int i=0,*ptr;
        pid_t pid;
        pid=fork();
        if(pid<0)
        {
                printf("child process is not created\n");
                exit(1);
        }
        if(pid>0)
        {
                /*while(i<=5)
                {
                        sleep(1);
                        i++;
                }*/
                w=waitpid(pid,&status,WUNTRACED);
                printf("terminated process child process id:%d\n",w);
                if(WIFEXITED(status))
                        printf("normal termination %d\n",WEXITSTATUS(status));
                else if(WIFSIGNALED(status))
                        printf("abnormal termination %d\n",WTERMSIG(status));
                else if(WCOREDUMP(status))
                        printf("coredump termination %d\n",WIFSTOPPED(status));
        exit(20);
        }
        else
        {
        //      sleep(10);
                printf("child process id:%d\n",getpid());
                while(i<=10000)
                {
                        if(i%1000==0)
                                printf("1\n");
                //      printf("%d\n",1/0);
                 /*       if(i==5000)
                                abort();   */
                        /*if(i==1000)
                        {
                                ptr=(int *)malloc(1*sizeof(int));
                                ptr=&i;
                                free(ptr);
                                printf("%d\n",*ptr);
                        }*/
                //        if(i%1000==0)
                 //               printf("*");
                        i++;
		}
		exit(30);
	}
}

