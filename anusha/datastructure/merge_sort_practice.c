#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
void insert(int num);
void insert1(int num);
void display();
void display1();
void main()
{
	int num,opt;
	while(1)
	{
		printf("\n\t0.exit\n\n\t1.Add nodes at list 1\n\n\t2.Add nodes at list 2\n\n\t3.Display of List 1\n\n\t4.Display of List 2\n\n\t");
		printf("\nEnter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("Enter the element:");
				scanf("%d",&num);
				insert(num);
				break;
			case 2:printf("Enter the element:");
				scanf("%d",&num);
				insert1(num);
				break;
				
			case 3:display();
				break;
			
			case 4:display1();
				break;
			
			default:printf("Invalid option:");
			
		}
		printf("\n...............................................................\n");
	}		
}

void insert(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=head1;
	head1=ptr;
	
}

void insert1(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=head2;
	head2=ptr;
	
}
void display()
{
	struct node *temp;
	temp=head1;
	printf("\nDisplay of list 1\n");
	while(temp!=NULL)
	{
		
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}

void display1()
{
	struct node *temp;
	temp=head2;
	printf("\nDisplay of list 2\n");
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}
