#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void add_before_a_node(int num,int val)
{
	struct node *prev,*cur,*ptr;
	if(head==NULL)//list is empty
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num);
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory in heap\n");
				exit(1);
			}
		ptr->data=val;
		ptr->link=head;
		head=ptr;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap\n");
					exit(1);
				}
			ptr->data=val;
			ptr->link=cur;
			prev->link=ptr;
			//cur=ptr;
			return;
		}
	}
	prev=cur;
	cur=cur->link;
	printf("Element is not found\n");
}	

