#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void add_node_at_last(int num)
{
	struct node* temp;
	struct node* ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL)//when list is empty and new node is added
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)//when list contains nodes
	{
		temp=temp->link;
	}
	temp->link=ptr;
}
