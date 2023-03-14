//swapping the inputs and getting the output as aa22cc44

#include<stdio.h>
void main()
{
	unsigned int x = 0x11223344;
	unsigned int y = 0xaabbccdd;
	unsigned int z;//0xaa22cc44
	unsigned int *ptr1,*ptr2,*ptr3;
	ptr1 = &x;
	ptr2 = &y;
	ptr3 = &z;
	(((unsigned char *)ptr3)[0])=(((unsigned char *)&x)[0]);
	(((unsigned char *)ptr3)[1])=(((unsigned char *)&y)[1]);
	(((unsigned char *)ptr3)[2])=(((unsigned char *)&x)[2]);
	(((unsigned char *)ptr3)[3])=(((unsigned char *)&y)[3]);
	printf("%x\n",z);
}
