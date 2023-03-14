/*#include<stdio.h>
main()
{
	
	int x=1;
	while(x<=10)
	{
	printf("%d\n",x);
	x++;
	}
}*/

/*#include<stdio.h>
main()
{
	char x=1;
	while(x>0)
	{
	x++;
	}
	printf("%d\n",x);
}*/

/*#include<stdio.h>
main()
{
	unsigned char x=1;
	while(x>0)
	{
	x++;
	}
	printf("%d\n",x);
}*/

/*#include<stdio.h>
main()
{
	int x=9;
	while(x!=0)
	{
	printf("%d\n",x);
	x=x-2;
	}
	printf("%d\n",x);
}*/
/*#include<stdio.h>
main()
{
	int x=9;
	while(x>=0)
	{
	printf("%d\n",x);
	x=x-2;
	}
	printf("%d\n",x);
}*/


#include<stdio.h>
main()
{
	int num,temp,rem,sum=0,i=1;//i is power of 10
	printf("enter a number");
	scanf("%d",&num);
	temp=num;
	while(temp!=0)
	{
	rem=temp%2;
	temp=temp/2;
		if(rem>1)
		{
			sum=0;
			printf("invalid address\n");
			break;
		}
	sum=sum+i*rem;
	i=i*10;
	}
	printf("binary value %d\n",sum);
}
