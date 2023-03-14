#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;
void insert(int num);
void bubble_sort_swap_link();
void display();
void main()
{
	int num,opt,val;
	while(1)
	{
		printf("\nMenu\n0.exit\n1.insert data\n2.Bubble sort\n3.Display\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("Enter the data:");
				scanf("%d",&num);
				insert(num);
				break;
				
			case 2:
				bubble_sort_swap_link();
				break;
			case 3:display();
				break;
			default:printf("Invalid option:");
		}
		printf("\n.........................................................\n");
	}
}

void insert(int num)
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
	if(rear==NULL)
	{
		rear=front=ptr;
		return;
	}
	rear->link=ptr;
	rear=ptr;
}

void bubble_sort_swap_link()
{
	struct node *p,*q,*r,*s,*temp,*e;
	for(e=NULL;front->link!=e;e=q)
	{
		for(r=p=front;p->link!=e;r=p,p=p->link)
		{
			q=p->link;
			if(p->data > q->data)
			{
				p->link=q->link;
				q->link=p;
				if(p!=front)
					r->link=q;
				else
					front=q;
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
}

void display()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}
	
