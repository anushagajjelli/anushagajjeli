#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void reverse_the_list()
{
	struct node *prev,*cur,*next;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head =prev;
}
