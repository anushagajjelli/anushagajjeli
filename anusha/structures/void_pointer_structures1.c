//wap to swap dynamically

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct book
{
	char name[32];
	int nop;
	float price;
};


struct book* memory_alloc();
void read(struct book *ptr);
void swap(struct book* s1,struct book* s2);
void display(struct book *ptr);
void memory_dealloc(struct book *ptr);

main()
{
	struct book *b1,*b2;
	b1=memory_alloc();
	b2=memory_alloc();
	read(b1);
	read(b2);
	swap(b1,b2);
	display(b1);
	display(b2);
	memory_dealloc(b1);
	memory_dealloc(b2);
}

struct book* memory_alloc()
{
	struct book *ptr=(struct book*)malloc(1*sizeof(struct book));
	return ptr;
}

void read(struct book *ptr)
{
	printf("enter the book name\n");
	 scanf("%s",ptr->name);
	 __fpurge(stdin);
	 	
	 printf("enter the nop\n");
	 scanf("%d",&ptr->nop);
	 __fpurge(stdin);
	 	
	 printf("enter the price\n");
	 scanf("%f",&ptr->price);
	 __fpurge(stdin);
}

void swap(struct book* s1,struct book* s2)
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

void memory_dealloc(struct book *ptr)
{
	free(ptr);
}
