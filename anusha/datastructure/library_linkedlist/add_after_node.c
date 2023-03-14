#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void add_after_a_node(int num,int val)
{
	struct node* temp,* ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory in heap\n");
				exit(0);
			}
			ptr->data=val;
			ptr->link=NULL;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}
		temp=temp->link;
	}
	printf("Element is not found\n");
}
