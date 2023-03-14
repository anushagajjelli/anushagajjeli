//wap to convert int to ascii

#include<stdio.h>
#include<string.h>
int src[100],i;
int int_ascii(int num);
main()
{
	int num,temp,sum=0,rem;
	printf("enter a integer number:");
	scanf("%s",&src);
	int_ascii(src);
	printf("%s",src);
}

int int_ascii(int num)
{
	int temp,sum=0,rem;
	for(i=0;src[i]!='\0';i++)
	{	
		if((src[i]>=0)&&(src[i]<=9))
		{
			//rem=num%10;
			temp=src[i]+48;
			sum=sum*10+temp;
		}
		
	}
	
	return sum;
}
