#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void main()
{
	int i=0,j;
	alarm(2);
        j=alarm(10);
	printf("j=%d\n",j);

	while(1)
	{
		printf("hi");
		
	}
}

