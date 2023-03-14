#include<stdio.h>
main()
{
	unsigned int x;
	unsigned int a,b,temp;
	printf("enter a hexa value");
	scanf("%x",&x);
	printf("enter bit values");
	scanf("%d%d",&a,&b);
	if(((a>=0)&&(a<=31))<((b>=0)&&(b<=31)))
	{
		if (a>b)
		{
			temp=a;
			a=b;
			b=temp;
			printf("bit1 is %d bit2 is %d are changed",a,b);
			x=(x&(~((0xF<<4)|(0xF<<24))))|((x&(0xF<<4))<<(24-4))|((x&(0xF<<23))<<(24-4));
			printf("%x\n",x);
		}
		else
			{
				printf("bit1 is %d bit2 is %d",a,b);
				x=(x&(~((0xF<<4)|(0xF<<24))))|((x&(0xF<<4))<<(24-4))|((x&(0xF<<24))<<(24-4));
				printf("%x\n",x);
			}
	}
	else
		printf("invalid inputs");
}
