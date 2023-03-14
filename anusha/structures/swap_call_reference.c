//wap swapping of variables using call by reference function

#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};

main()
{
	struct book b1={"C-programming",550,700};
	struct book b2={"DS",300,800};
	swap(&b1,&b2);
	display(&b1);
	display(&b2);
}

void swap(struct book *s1,struct book *s2)
{
	struct book temp;
	strcpy(temp.name,s1->name);
	strcpy(s1->name,s2->name);
	strcpy(s2->name,temp.name);
	
	temp.nop=s1->nop;
	s1->nop=s2->nop;
	s2->nop=temp.nop;
	
	temp.price=s1->price;
	s1->price=s2->price;
	s2->price=temp.price;
}

void display(struct book *ptr)
{
	printf("%p-%s\n",ptr->name,ptr->name);
	printf("%p-%d\n",&ptr->nop,ptr->nop);
	printf("%p-%f\n",&ptr->price,ptr->price);
}
	
