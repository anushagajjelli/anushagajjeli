#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void delete_at_beginning()
{
	struct node* temp;
	int x;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	x=temp->data;
	free(temp);
	printf("Deleted element is %d\n",x);
}
