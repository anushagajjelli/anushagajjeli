
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
int count(int num)
{
	struct node* temp;
	int c=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}
