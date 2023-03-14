#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	int priority;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL;
void insert(int num,int priority);
void display();
void main()
{
	int num,priority_value,opt;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Insert\n\t2.Display\n\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:printf("Enter the data :");
			       scanf("%d",&num);
			       __fpurge(stdin);
			       printf("Enter the priority:");
			       scanf("%d",&priority_value);
			       insert(num,priority_value);
			       break;

			case 2:display();
			       break;

			default:printf("Invalid option");
		}
	}
}

void insert(int num,int priority_value)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->priority=priority_value;
	if(head==NULL)
	{
		ptr->prev=ptr->next=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==priority_value)
		{
		
			if(temp->next==NULL)
				break;
		}
		temp=temp->next;
	}
	
	while(temp->next==NULL)//adding node at last with same priority
	{
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next=ptr;
		return;
	}
	while(temp->next!=NULL)
	{
		ptr->next=temp->next;
		ptr->prev=temp;
		temp->next->prev=ptr;
		temp->next=ptr;
		return;
	}
	
	temp=head;

	while(temp!=NULL)
	{
		if(temp->priority<priority_value)
		{

			if(temp->next==NULL)
				break;

		}
		temp=temp->next;
	}
	while(temp->next==NULL)
	{
		ptr->next=temp->next;
		ptr->prev=temp;
		if(temp->next!=NULL)
			temp->next->prev=ptr;
		temp->next=ptr;
		return;
	}











}



void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d-%d\n",temp->data,temp->priority);
		temp=temp->next;
	}
}
