//wap to print int to ascii

#include<stdio.h>
void int_ascii(int num);
main()
{
	int num;
	printf("enter a integer number:");
	scanf("%d",&num);
	int_ascii(num);
	
}

void int_ascii(int num)
{
	char src[10];
	int i,rem,temp,count=0;
	temp=num;
	while(temp>0)
	{
		rem=temp%10;
		temp=temp/10;
		count++;
	}
	i=count;
	printf("count-%d\n",i);
	src[i]='\0';
	for(i=i-1;i>=0;i--)
	{
		rem=num%10;
		if((rem>=0)&&(rem<=9))
		{
			src[i]=rem+48;
			num=num/10;
		}
	}
	printf("%s\n",src);
}
	
