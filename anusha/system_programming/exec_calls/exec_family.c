//wap to implement the exec family calls

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int a=5,b=6,c,k;
//	scanf("%d",&k);
//	c=a+b;
	printf("Addition of two elements:%d\n",c);
//	execlp("cat","cat","v_fork.c",NULL);
//	execl("/bin/ps","ps","-ef",NULL);
 	execl("/home/engineer/anusha/system_programming/v_fork"
,"v_fork.c",NULL);

}
	
