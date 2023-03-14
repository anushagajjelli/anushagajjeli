#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void swap_by_data(int num1,int num2)
{
	struct node *p1,*p2;
	int temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p1=p2=head;
	while(p1!=NULL)
	{
		if(p1->data==num1)
			break;
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(p2->data==num2)
			break;
		p2=p2->link;
	}
	if((p1==NULL)||(p2==NULL))
	{
		printf("Data not found\n");
		return;
	}
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}
