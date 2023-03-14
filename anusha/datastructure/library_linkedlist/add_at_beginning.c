#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void add_at_beginning(int num)
{
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}
