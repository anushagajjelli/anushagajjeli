
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void delete_last_node()
{
	struct node *prev,*cur;//prev->previous node and cur->current node
	if(head==NULL)//when list is empty
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)//when list contains only a single node
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur->link!=NULL)//when list contains more nodes
	{
		prev=cur;
		cur=cur->link;
	}
	free(cur);//deallocating the last node
	prev->link=NULL;//updating the null to the previous node(last to 2nd node)
}

