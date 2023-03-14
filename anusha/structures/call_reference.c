//wap using call by reference

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
	display(&b);
}

void display(struct book *ptr )
{
	printf("%s\n",ptr->name);
	printf("%d\n",ptr->nop);
	printf("%f\n",ptr->price);
}	
