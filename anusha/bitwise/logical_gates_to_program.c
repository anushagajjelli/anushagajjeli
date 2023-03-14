//wap c program to convert logical gates into c program

#include<stdio_ext.h>
struct bitfield 
{
	unsigned char a:1,b:1,c:1,d:1;
}gate;


void main()
{
	unsigned char  xor,and,or,temp;
	gate.a=1,gate.b=1,gate.c=1,gate.d=1;

	temp=!((gate.a)^(gate.b));
	printf("temp value:%d\n",temp);

	and=(gate.c) & (gate.d);
	printf("and value:%d\n",and);

	or=temp|and;
	printf("final output:%d\n",or);
}



