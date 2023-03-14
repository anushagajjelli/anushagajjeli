/*#include<stdio.h>
main()
{
	unsigned int x=0x11223344;
	unsigned int clr,sft1,sft2,total,temp;
	clr=(x&(~((0Xff<<0)|(0Xff<<16))));
	sft1=((x&(0xff<<0))<<16);
	sft2=((x&(0xff<<16))>>16);
	total=(clr|sft1|sft2);
	temp=(sft1|sft2);
	printf("%x\n",total);
	printf("%x\n",temp);
}*/



//swapping byte problem
/*#include<stdio.h>
main()
{
	unsigned int x=0x11223344;
	unsigned int b;
	b=(((x&(0xff<<0))<<8)|((x&(0xff<<16))>>16));// check status,44 light shift with 8bits and 22 rightside with 16bits ...then perform or operation
	printf("%x\n",b);
}*/



//wap to check even or odd using bitwise operator

/*#include<stdio.h>
main()
{
	unsigned int x;
	printf("enter the value\n");
	scanf("%x",&x);
	if((x&(0x1<<0))==0)//check the msb bit status ...if msb is 0->even ..else msb is 1-odd
		printf("even number:");
	else 
	printf("odd number:");
}*/

//wap to print ascii character to integer constant

/*#include<stdio.h>
main()
{
	unsigned char x;
	printf("enter the ascii character\n:");
	scanf("%c",&x);
	if((x>=48)&&(x<=57))
	printf("%c->%d\n",x,(x-48));
}*/



//wap to swap two numbers without 3rd variable using bitwise operator
#include<stdio.h>
main()
{
	unsigned int x=4;
	unsigned int y=7;
	printf("before swapping %d-%d\n",x,y);
	x=x^y;//x=4^7=3
	y=x^y;//y=3^7=4
	x=x^y;//x=3^y=7
	printf("after swapping %d-%d\n",x,y);
}
