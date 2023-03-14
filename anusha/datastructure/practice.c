#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

int x=0;
struct node *head=NULL;
void push(int num);
void pop();
void display();
int count();
int search(int num);
void delete_entire_stack();
void main()
{
	int num,opt,s,k;
	while(1)
	{
		printf("\n\t0.exit\n\t1.push\n\t2.pop\n\t3.display\n\t4.count\n\t5.search\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
				
			case 1:x++;
				printf("enter the number:");
				scanf("%d",&num);
				push(num);
				break;
			case 2:x--;
				pop();
				break;
			case 3:display();
				break;
			case 4:k=count();
				printf("Count of the elements in stack-%d",k);
				break;
			case 5:printf("Enter the number to be searched:");
				scanf("%d",&num);
				s=search(num);
				if(s==0)
				{
					printf("Element is not found\n");
				}
				else
					printf("Element found at %d",(x-s)+1);
				break;
			
			case 6:delete_entire_stack;
				break;
							
			default:printf("Invalid option\n");
		}
		printf("\n..............................................................................\n");
	}
	
}

void push(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

void pop()
{
	struct node *temp;
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

int count()
{
	int c=0;
	struct node *temp;
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
	int pos=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
}
			
