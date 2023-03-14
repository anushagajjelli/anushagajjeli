#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	int freq;
	struct node *link;
};
struct node *head=NULL;
void insert(int num);
void frequency();
void delete_repeated();
void display();
void delete_entire_list();
void delete();
void zeros();
void highest();
int flag=0;
int x=0;
void main()
{
	int opt,num;
	while(1)
	{
		printf("\n\n0.exit\n\n1.Insert\n\n2.Frequency of data\n\n3.Delete repeated node\n\n4.Display\n\n5.Delete entire list\n\n6.Delete the node\n\n7.zeros\n\n8.Highest node in the list\n\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:if(x==0)
				      delete_entire_list();
				exit(0);
			
			case 1:printf("Enter the data:");
				scanf("%d",&num);
				insert(num);
				break;

			case 2:flag++;
				frequency();
				break;
			
			case 3:delete_repeated();
				break;	       
			case 4:display();
				break;
			 case 5:x++;
			       delete_entire_list();
				break;

			case 6:delete();
			       break;
			case 7:zeros();
			       break;
			       
			 case 8:highest();
			 	break;
			default:printf("Invalid option:");
		}
	}
}

void insert(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL)
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=ptr;
}

void delete()
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

void frequency()
{
	struct node *temp,*p,*q;
	int c=0;
	for(p=head;p!=NULL;p=p->link)
	{
		for(q=head;q!=NULL;q=q->link)//it will check from first node 
		{
			if(p->data==q->data)//p and q will point same element so count will increment 1 time, so c=0 initially
			{
				c++;
				//p->freq=c;
				
			}
		}
		p->freq=c;
		c=0;
	}
}

void delete_repeated()
{
	struct node *p,*q,*s,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->link)
	{
		for(s=p,q=p->link;q!=NULL;s=q,q=q->link)
		{
			if(p->data==q->data)
			{
				s->link=q->link;
				free(q);
				q=s;
			}
			
		}
	}
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
	while(temp!=NULL)
	{
		if(flag==0)
			printf("%d\n",temp->data);
		else
		{
			if(temp->freq!=0)
				printf("%d-%d\n",temp->data,temp->freq);
		}
		temp=temp->link;
		
	}
	
}

void delete_entire_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(head!=NULL)
	{
		temp=head;
		head=head->link;
		free(temp);
	}
	printf("Data is deleted\n");

}

void zeros()
{
	struct node *p,*q;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
		for(p=head;p!=NULL;p=p->link)
		{
			for(q=p->link;q!=NULL;q=q->link)
			{
				if(p->data==q->data)
				{
					q->freq=0;
				}
			}
		}
}

void highest()
{
	struct node *p;
	int temp=0;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->link)
	{
		if(temp<p->freq)
		{
			temp=p->freq;
		}
	}
	for(p=head;p!=NULL;p=p->link)
	{
		if(temp==p->freq)
		printf("Highest element of the list -%d\n",p->data);
	}
	
}

	
