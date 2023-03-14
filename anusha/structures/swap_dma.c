//wap to perform swap operation using the dma calls(allocate memory dynamically)

#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};

main()
{
	struct book *b1,*b2;
	b1=memory_alloc();
	b2=memory_alloc();
	if((b1==NULL)&&
