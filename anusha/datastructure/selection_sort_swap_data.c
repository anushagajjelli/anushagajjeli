#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

struct node*head=NULL;
void insert(int num);
void selection_sort();
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
				
			case 2:selection_sort();
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

void selection_sort()
{
	struct node *p,*q;
	int temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	for(p=head;p->link!=NULL;p=p->link)
	{
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
	//printf("Least element :");
//		printf("%d",head->data);
	//printf("Biggest element:");
	//	printf("%d",rear->data);
	
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
	
