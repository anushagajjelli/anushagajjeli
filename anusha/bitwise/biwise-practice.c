/*#include<stdio.h>
int main()
{
	int i=1;
	while(i<7);
	i++;
	printf("%d\n",i);
	return 0;
}*/
	


/*#include<stdio.h>
main()
{
	int i;
	for(i=0;i<=10;i++);
	printf("%d",i);
}*/






/*#include<stdio.h>
main()
{
	int x=1;
	while(x<=10);
	{
		printf("%d\n",x);
	}
}*/


/*#include<stdio.h>
int main()
{
	int i=1,j=3;
	while(i<5)
	{
		i++;
		if(j==0)
			break;
		j--;
	}
	printf("%d %d\n",i,j);
	return 0;
}*/



#include<stdio.h>
main()
{
	int x=5;
	printf("%d",x=x==6);
}


















/*#include<stdio.h>
main()
{
	int x=0x123456;
	int clr,sft1,sft2,sft3,sft4,total;
	clr=(x&(~((0xff<<16)|(0xff<<0))));
	printf("%x",clr);
	sft1=((x&(0xf<<0))<<(16-0));//6 moving to 2's place 
	printf("%x",sft1);
	sft2=((x&(0xf<<4))<<(20-4));//5 moving to 1's place
	printf("%x",sft2);
	sft3=((x&(0xf<<16))>>(16-4));
	printf("%x",sft3);
	sft4=((x&(0xf<<20))>>(20-0));
	printf("%x",sft4);
	total=(sft1|clr|sft2|sft3|sft4);
	printf("%x\n",total);
	
}*/


/*#include<stdio.h>
int main()
{
	int x=0x123456;
	
	x=(x&(~((0xff<<16)|(0xff<<0))))|((x&(0xf<<0))<<(16-0))|((x&(0xf<<4))<<(20-4))|((x&(0xf<<16))>>(16-4))|((x&(0xf<<20))>>(20-0));
	printf("%x\n",x);
	
}*/




