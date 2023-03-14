
//wap c program to convert logical gates into c program

#include<stdio_ext.h>


void main()
{
	unsigned int a,b,c,d ,xor,and,or,temp;
	//gate.a=1,gate.b=1,gate.c=1,gate.d=1;

	printf("Enter the inputs for x-or gate:");
	scanf("%d %d",&a,&b);
	printf("Enter the inputs for and gate:");
	__fpurge(stdin);
	scanf("%d %d",&c,&d);
			
	temp=!((a)^(b));
	printf("temp value:%d\n",temp);

	and=(c) & (d);
	printf("and value:%d\n",and);

	or=temp|and;
	printf("final output:%d\n",or);
}

