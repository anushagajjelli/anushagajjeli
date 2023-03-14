/*#include<stdio.h>
main()
{
	unsigned int num,temp,sum=0,rem;
	printf("enter a input");
	scanf("%d",&num);
	temp=num;
	while(temp>0)
	{
		rem=temp%10;
		sum=sum*10+rem;
		temp=temp/10;
	}
	printf("%d\n",sum);
	if(sum==num)
		printf("palindrome");
	else
		printf("not a palindrome");
}*/
	


/*#include<stdio.h>
main()
{
	unsigned int num,temp,sum=0,rem;
	printf("enter a input");
	scanf("%d",&num);
	temp=num;
	while(temp>0)
	{
		rem=temp%10;
		sum=sum+(rem*rem*rem);
		temp=temp/10;
	}
	printf("%d\n",sum);
	if(sum==num)
		printf("armstrong number");
	else
		printf("not a armstrong number");
}*/

/*#include<stdio.h>
main()
{
	unsigned int min,max,sum=0,temp,rem;
	printf("enter the range");
	scanf("%d %d",&min,&max);
	do
	{
		sum=0;
		temp=min;
		do
		{
			rem=temp%10;
			sum=sum*10+rem;
			temp=temp/10;
		}while(temp>0);
			printf("%d %d\n",sum,min);
		min++;
	}
	while(min<=max);
}*/



/*armstrong using nested do while loop*/
/*#include<stdio.h>
main()
{
	unsigned int min,max,temp,sum=0,rem;
	printf("enter a range");
	scanf("%d %d",&min,&max);
	do
	{
		temp=min;
		sum=0;
		do
		{
			rem=temp%10;
			sum=sum+(rem*rem*rem);
			temp=temp/10;
		}while(temp>0);
			printf("%d %d\n",sum,min);
			min++;
	}
		while(min<=max);
	
		
}*/


/*sum of digits using the nested do while loop*/
/*#include<stdio.h>
main()
{
	unsigned int min,max,temp,sum=0,rem;
	printf("enter a range");
	scanf("%d %d",&min,&max);
	do
	{
		temp=min;
		sum=0;
		do
		{
			rem=temp%10;
			sum=sum+rem;
			temp=temp/10;
		}while(temp>0);
			printf("%d %d\n",sum,min);
			min++;
	}
		while(min<=max);
	
		
}*/


#include<stdio.h>
main()
{
	int min,max,sum=0,rem,temp;








