#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;
void add_at_beginning(int num);
void delete_at_beginning();
void display();
int count(int num);
int search(int num);
void main()
{
	int num,opt,k,s;
	while(1)
	{
		printf("\n\t0.exit\n\t1.Add at beginning\n\t2.Delete at beginning\n\t3.Display\n\t4.Count\n\t5.Search\n\t6.Delete entire list\n\t");
		printf("Enter the options:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0: exit(0);
			
			case 1: printf("Enter the number:");
				scanf("%d",&num);
				add_at_beginning(num);
				break;
				
			case 2:delete_at_beginning();
				break;
			
			case 3:display();
				break;
				
			case 4:k=count(num);
				printf("Count ot the elements in the list-%d",k);
				break;
				
			case 5:printf("Enter the number to be searched:");
				scanf("%d",&num);
				s=search(num);
				if(s==0)
					printf("Element is not found in the list\n");
				else
					printf("Element found at %d",s);
				break;
			
			default:printf("Invalid option\n");
		}
		printf("\n.....................................................\n");
	}
}	

void add_at_beginning(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=NULL;
	head=ptr;
}

void delete_at_beginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	free(temp);
}	

void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}

int count(int num)
{
	int c=0;
	struct node* temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}

int search(int num)
{
	struct node *temp;
	int pos=0;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
}
				
