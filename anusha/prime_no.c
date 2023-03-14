//wap to print the prime numbers in given range

#include<stdio.h>
void main()
{
	int min,max;
	//int num;
	int i=2,c=0;
	printf("Enter the range:");
	scanf("%d %d",&min,&max);
	//printf("Enter the number:");
	//scanf("%d",&num);
	while(min<=max)
	{
		//printf("hello");
		while(i<=min)
		{
			if(min%i==0)
				c++;
			i++;

			
		}
			if(c==1)
				printf("prime number:%d\n",min);
		c=0;
		i=2;
		min++;
	
		/*else
			printf("not a prime number\n");*/
	}
}


	
