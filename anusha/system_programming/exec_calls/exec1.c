//wap to verify the exec family calls

#include<stdio.h>
#include<unistd.h>
void main()
{
	printf("Hiii\n");
	//execl("/bin/cat","cat","v_fork.c",0);
	execl("/home/engineer/anusha/system_programming/v_fork","v_fork.c",NULL);
	



	printf("hello\n");
}
