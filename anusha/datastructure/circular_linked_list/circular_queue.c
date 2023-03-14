//wap to perform the single circular queue linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

struct node *rear=NULL;
struct node *front=NULL;

void insert(int num);
void delete();
void display();

void main()
{
	int opt,k,c,i,val,num;
	while(1)
	{
		printf("\nMenu\n\n\t0.exit\n\n\t1.Add at beginning\n\n\t2.Delete at beginning\n\n\t3.Display\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:
			       printf("Enter the number:");
			       scanf("%d",&num);
			       insert(num);
			       break;

		       case 2:delete();
				break;

			case 3:display();
			       break;
			       
			
			default:printf("Invalid option:");
		}
	}
}


void insert(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(1);
	}
	ptr->data=num;
	if(rear==NULL)
	{
		rear=front=ptr;
		ptr->link=ptr;
		return;
	}
	temp=front;
	while(temp->link!=front)
		temp=temp->link;
	ptr->link=temp->link;
	rear=temp->link=ptr;
	printf("%p\n",rear);
}


void display()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=front;
	do{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
	while(temp!=front);
	printf("%p\n",rear);
}


void delete()
{
	struct node *temp,*t;
	if(front==NULL)
	{
		printf("List is empty\n");
		return;
	}
	t=temp=front;
	while(temp->link!=front)
		temp=temp->link;
	front=front->link;
	temp->link=front;
	free(t);
}


