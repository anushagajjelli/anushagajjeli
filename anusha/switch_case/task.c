#include<stdio.h>
main()
{
	int opt,num,temp,i,rem,sum=0,count=0;
	printf("select the option : 1.reverse the number\n2.sum of digits\n3.count the number\n4.binary value\n5.even or odd number\n");
	scanf("%d",&opt);
	printf("enter the number\n");
	scanf("%d",&num);
	switch(opt)
	{
	case 1:temp=num;
		sum=0;
		while(temp>0)
		{
			rem=temp%10;
			temp=temp/10;
			sum=sum*10+rem;
		}	
		printf("%d\n",sum);
		break;

	case 2:temp=num;
		sum=0;
		while(temp>0)
		{
			rem=temp%10;
			temp=temp/10;
			sum=sum+rem;
		}
		printf("%d\n",sum);
		break;
	
	case 3: count=0;
		if(num!=0)
		{
			while(num>0)
			{
				num=num/10;
				count++;
			}
		}
		else
		count++;
		printf("%d\n",count);
		break;

	case 4:temp=num;
		sum=0;
		i=1;
		while(temp!=0)
		{
			rem=temp%2;
			temp=temp/2;
			sum=sum+i*rem;
			i=i*10;
		}
		printf("%d\n",sum);
		break;

	case 5:if(num%2==0)
		printf("even number\n");
		else
		printf("odd number\n");
		break;
	default:
		printf("out of the options\n");
	}
}		

