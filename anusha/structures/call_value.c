//wap using call by value

#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};

main()
{
	struct book b={"C_programming",550,350};
	display(b);
}

void display(struct book b)
{
	printf("%s\n",b.name);
	printf("%d\n",b.nop);
	printf("%f\n",b.price);
}	
