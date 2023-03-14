#include<stdio.h>
#include<unistd.h>
void main()
{
	float k=2.000000;
	while(k!=3.0)
	{
		printf("%f\n",k);
		printf("%d\t%d\n",sizeof(k),sizeof(3.0));
		sleep(2);
		k=k+0.2;
	}
}
		

