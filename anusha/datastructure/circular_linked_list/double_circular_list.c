//WAP to perform the double circular linked list

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL;
void add_at_beginning(int num);
void display();
void add_at_last(int num);
void add_afteranode(int num,int val);
void add_before_node(int num,int val);
void delete_at_beg();
void main()
{
	int num,opt,val;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Insert\n\t2.Display\n\t3.Add at last\n\t4.Add after the node\n\t5.Add before node\n\t6.Delete at beginning\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:printf("Enter the number:");
			       scanf("%d",&num);
			       add_at_beginning(num);
			       break;

			case 2:display();
			       break;

			 case 3:printf("Enter the last node data:");
				scanf("%d",&num);
				add_at_last(num);
				break;
			
			case 4:printf("Enter the number:");
			       __fpurge(stdin);
			       scanf("%d",&num);
			       printf("Enter the new node :");
			       __fpurge(stdin);
			       scanf("%d",&val);
			       add_afteranode(num,val);
			       break;

			case 5:printf("Enter the number:");
                               __fpurge(stdin);
                               scanf("%d",&num);
                               printf("Enter the new node :");
                               __fpurge(stdin);
                               scanf("%d",&val);
                               add_before_node(num,val);
                               break;

			case 6:delete_at_beginning();
			       break;


			default:printf("Invalid option");
		}

		printf("\n.......................................................................\n");
	}
}

void add_at_beginning(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory :");
		exit(1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->next=ptr->prev=ptr;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=head)
		temp=temp->next;
	ptr->next=head;
	ptr->prev=temp;
	ptr->next->prev=ptr;
	head=temp->next=ptr;
}


void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	do
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
	while(temp!=head);
}

		
void add_at_last(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(3);
	}
	ptr->data= temp=temp->next;
num;
	if(head==NULL)
	{
		ptr->next=ptr->prev=ptr;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=head)
		temp=temp->next;
	ptr->next=temp->next;
	ptr->prev=temp;
	ptr->prev->next=ptr;
	head->prev=ptr;
	
}

void add_afteranode(int num,int val)
{
	struct node *ptr;
	struct node *temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("there is no memory in heap segment\n");
		exit(1);
	}
	ptr->data=val;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==head)
		{
			ptr->next=ptr->prev=head;
			ptr->prev->next=ptr;
			head->prev=ptr;
			return;
		}
		ptr->next=head->next;
		ptr->prev=head;
		ptr->prev->next=ptr;
		ptr->next->prev=ptr;
		return;
	}
	temp=head->next;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			if(temp->next==head)
				temp->next->prev=ptr;
			ptr->next=temp->next;
			ptr->prev=temp;
			ptr->prev->next=ptr;
			return;
		}
		temp=temp->next;
	}
	printf("Element not found\n");
}

void add_before_node(int num,int val)
{
        struct node *ptr;
        struct node *temp,*prev;
        if(head==NULL)
        {
                printf("list is empty\n");
                return;
        }
	if(head->data==num)
	{
		 ptr=(struct node *)malloc(1*sizeof(struct node));
	        if(ptr==NULL)
       		 {
               		 printf("there is no memory in heap segment\n");
              		  exit(1);
       		 }
    	        ptr->data=val;
		ptr->next=head;
                ptr->prev=head->prev;
                head=ptr;
                ptr->next->prev=ptr;
                ptr->prev->next=ptr;
                return;
	}
	prev=head;
	temp=temp->next;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			  ptr=(struct node *)malloc(1*sizeof(struct node));
               		 if(ptr==NULL)
                	 {
                        	 printf("there is no memory in heap segment\n");
                         	 exit(1);
                	 }
              	         ptr->data=val;

			ptr->prev=prev;
			ptr->next=temp;
			ptr->prev->next=ptr;
			ptr->next->prev=ptr;
		}
		prev=temp;
		temp=temp->next;
	}
}


void delete_at_beginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->next!=head)
		temp=temp->next;
	temp->next=head->next;
	free(head);
	head=temp->next;
}

