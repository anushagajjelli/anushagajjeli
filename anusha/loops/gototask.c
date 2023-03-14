#include<stdio.h>
main()
{
	int min,max,i=1,sum=0,temp,rem;
	printf("enter the min and max values\n");
	scanf("%d %d",&min,&max);
	temp:temp=min;
		sum=0;
		i=1;
		goto begin;
	begin:if(temp>0)
		{
			rem=temp%10;
			if(rem>1)
			{
				min++;
				goto temp;
			}
				temp=temp/10;
				sum=sum+i*rem;
				i=i*2;
				if(temp>0)
				goto begin;
		}
		printf("%d-%d\n",min,sum);
			min++;
			if(min<=max)
				goto temp;
}
			
