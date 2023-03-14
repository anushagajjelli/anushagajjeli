#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("Failed to create child\n");
		exit(1);
	}
	else if(pid>0)
	{
		printf("%p-%d\n",
