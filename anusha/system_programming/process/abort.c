//wap to check the abort function....signal used

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int x=1;
	while(x>0)
	{
		printf("Hi\n");
		if(x==15)
		{
			abort();
		}
		x++;
	}
}