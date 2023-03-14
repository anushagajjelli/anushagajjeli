//wap to verify the system call of raise.....raise will terminate the current process/itself

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//#include<sys/types.h>
int  main()
{
	int x=10,signalno;//signal number for kill is 9
	scanf("%d",&signalno);
//	printf("1");
        while(x>0)
	{
		printf("Hi\n");
	//	printf("*\n");
		if(x==5)
		{
			raise(signalno);
		}
		x--;
	}

}


