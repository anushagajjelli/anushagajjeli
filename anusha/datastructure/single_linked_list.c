//wap to perform the single linked list


#include<stdio_ext.h>
#include<stdlib.h>
void add_at_beginning(int num);
void delete_at_beginning();
void display();
int count();
struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;
void main()
{
	int num,pos,opt,k;
	while(1)
	{
		printf("\nMenu\n0.exit\n1.Add at beginning\n2.Delete at beginning\n3.Display\n4.count\n5.search\n6.Delete the entire list\n");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
				break;
			
			case 1: printf("Enter the number to be add:");
				scanf("%d",&num);
				add_at_beginning(num);
				break;
				
			case 2:delete_at_beginning();
				break;
				
			case 3:display();
				break;
				
			case 4:k=count();
				printf("count of data-%d",k);
				break;
				
			case 5:printf("enter the number to be searched\n");
				scanf("%d",&num);
				if(pos==0)
				{
					
			
			default:printf("Invalid option\n");
		}
		printf("\n..................................................................\n");
	}
}

void add_at_beginning(int num)
{
	struct node*ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

void delete_at_beginning()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	free(temp);
}

void display()
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
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}

int count()
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
	
	
