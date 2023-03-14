#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
int count1;
struct node
{
	int data;
	struct node *link;
};
struct node *rear=NULL;
struct node *front=NULL;
void insert_data(int num);
void delete_data();
void display();
void count();
int search(int num);
void create_queue(int *iptr,int num);
void reverse_queue();
int main()
{
	int prog,num,res,*ptr,i;
	while(1)
	{
		printf("*******************Queue implementation*****************\n");
		printf("0.Exit the program\n1.Insert operation\n2.Delete the data\n3.Display queue\n4.Count the queue elements\n5.Search the elements\n6.Create a list\n7.Rverse the queue\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Exit the progam\n");
				exit(0);

			case 1:
				printf("Insert the data\n");
				scanf("%d",&num);
				insert_data(num);
				break;

			case 2:
				printf("Delete the data\n");
				delete_data();
				break;

			case 3:
				printf("display\n");
				display();
				break;

			case 4:
				printf("COunt\n");
				count();
				break;

			case 5:
				printf("Search for particular elements\n");
				scanf("%d",&num);
				res=search(num);
				if(res>0)
				{
					printf("Elements are found at %d position\n",res);
				}
				else
					printf("Elements are not found\n");
				break;

			case 6:
				printf("Create a list\n");
				ptr=(int *)malloc(sizeof(struct node));
				if(ptr==NULL)
				{
					printf("failed to allocate the memory in heap segment\n");
					exit(-1);
				}
				printf("Enter the count the number of elements\n");
				scanf("%d",&num);
				for(i=0;i<num;i++)
				{
					__fpurge(stdin);
					printf("Enter the %d index element\n",i);
					scanf("%d",&ptr[i]);
				}
				create_queue(ptr,num);
				free(ptr);
				break;

			case 7:
				printf("Reverse the queue\n");
				reverse_queue();
				break;
				
		}
	}
}
void insert_data(int num)
{
	struct node *temp;
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap segment\n");
		exit(-1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(rear==NULL)
	{
		front=rear=ptr;
	}
	rear->link=ptr;
	rear=ptr;
}
void delete_data()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	front=front->link;
	free(temp);
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
		printf("The Queue Data:-->>(%d)\n",temp->data);
		temp=temp->link;
	}
}
void count()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=rear->link)
	{
		count1++;
		temp=temp->link;
	}
	printf("The number of data in the Queue-->>%d\n",count1);
	count1=0;
}
int search(int num)
{
	int pos=0;
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return 0;
	}
	temp=front;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
		return pos;
		temp=temp->link;
	}
	return 0;
}
void create_queue(int *iptr,int num)
{
	struct node *temp;
	struct node *ptr;
        int i;  
        for(i=0;i<num;i++)
        {
		ptr=(struct node *)malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(-1);
		}
		ptr->data=iptr[i];
		ptr->link=NULL;
		if(rear==NULL)
		{
			rear=front=ptr;
		}
		rear->link=ptr;
		rear=ptr;
	}
}
void reverse_queue()
{
	struct node *temp,*prev,*cur;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front == rear)
	return;
	prev=NULL;
	cur=front;
	while(cur!=NULL)
	{
		temp=cur->link;
		cur->link=prev;
		prev=cur;
		cur=temp;
	}
	temp=front;
	front=prev;
	rear=temp;
	
}















