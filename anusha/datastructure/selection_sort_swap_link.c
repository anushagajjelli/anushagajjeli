#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void insert(int num);
void selection_sort_swap_link();
void display();
void main()
{
	int num,opt;
	while(1)
	{
		printf("\nMenu\n0.exit\n1.insert data\n2.selection sort\n3.Display\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("Enter the data:");
				scanf("%d",&num);
				insert(num);
				break;
				
			case 2:selection_sort_swap_link();
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
	/*if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}*/
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

void selection_sort_swap_link()
{
	struct node *p,*q,*r,*s,*temp;
	for(r=p=head;p->link!=NULL;r=p,p=p->link)
	{
		for(s=q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data > q->data)
			{
				temp=p->link;
				p->link=q->link;
				q->link=temp;
				if(p!=head)
					r->link=q;
				else
					head=q;
				s->link=p;
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
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}
	
