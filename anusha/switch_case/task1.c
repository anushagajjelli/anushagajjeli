#include<stdio.h>
main()
{
	int x,bit,i,j,zero=0,one=0,count=0,opt;
	printf("select the option\n1:count the zeros\n2:how many times 101 repeated\n3:print the binary value\n4:swap the bits from msb to lsb\n5:convert 101 to 111\n");
	scanf("%d",&opt);
	printf("enter the number");
	//scanf("%x",&x);
	switch(opt)
	{
	case 1:	scanf("%d",&x);
		zero=0;
		one=0;
		for(bit=31;bit>=0;bit--)
		{	
			if((x&0x1<<bit)==0)
				zero++;
			else
				one++;
		}	
		printf("%d %d\n",zero,one);
		break;

	case 2:scanf("%x",&x);
		for(i=0;i<(32-3);i++)
		{
			if(((x&0x7<<i)>>i)==(0x5))
				count++;
			
		}
		printf("%d\n",count);
		break;
	
	case 3:scanf("%d",&x);
		for(bit=31;bit>=0;bit--)
		{
			if((x&0x1<<bit)==0)
				printf("0");
			else
				printf("1");
		}
		break; 

	case 4:scanf("%x",&x);
		for(i=0,j=31;i<j;i++,j--)		 
		  if((x&0x1<<i)^(x&0x1<<j))	
		  {
			  x=(x&(~((0x1<<i)|(0x1<<j))))|((x&0x1<<i)<<(j-i))|((x&0x1<<j)>>(j-i));
		  }
		printf("%x\n",x);
		break;
	
	case 5:scanf("%x",&x);
		for(i=0;i<(32-3);i++)
		{
			if(((x&0x7<<i)>>i)==(0x5))
				x=x&(~(0x7<<i))^(0x7<<i);
			
		}
		printf("%x\n",x);
		break;
	default:printf("out of the options\n");
	}			
}
