//wap to check whether little or big endien architecture

#include<stdio.h>
void main()
{
	unsigned int x=0x11223344;
	unsigned char *ptr,y;
	unsigned int *ptr1=&x;
	int i;
	for(i=0;i<4;i++)
	{
		printf("%x",ptr1[i]);
	}
	printf("\n");
	ptr=(char*)&x;
//	printf("%x\n",*ptr);
//	(*ptr==0x44)?printf("little"):printf("big");

}
/*void main()
{
	int x=0x11223344;
	((x&(0xff))==0x44)?printf("l\n"):printf("b\n");
}*/
