
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void delete_particular_node(int num)
{
	struct node* prev,*cur;
	if(head==NULL)
	{
	
		printf("List id empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)//when only single node is present in the list
		{
			free(head);
			head=NULL;
			return;
		}
		cur=head;
		head=head->link;
		free(cur);
		head==NULL;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("Element is not found\n");
}
