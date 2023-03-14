#include<stdlib.h>
#include<stdio.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void delete_entire_list()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		head=head->link;
		free(temp);
		temp=head;
	}
	printf("Entire data in the list is deleted\n");
}	
