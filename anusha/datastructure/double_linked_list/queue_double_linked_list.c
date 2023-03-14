//wap to perform queue using double linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void insert(int num);
void delete();
void display();
void count();
int search(int num);
void delete_entire_list();
void reverse_list();
void create_list(int *iptr,int n);
void add_before_node(int num,int val);
void add_after_node(int num,int val);
void add_last_node(int num);
void delete_last_node();
void delete_duplicate();
void delete_particular_node(int num);
void swap_data(int num,int val);
void swap_address(int num,int val);
void main()
{
	int num,opt,k,c,*ptr,i,val;
	char sub_opt;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Count\n\t5.Search\n\t6.Delete the entire list\n\t7.Reverse the list\n\t8.Create the list\n\t9.Add before a node\n\t10.Add after a node\n\t11.Add node at last\n\t12.Delete last node\n\t13.Delete duplicate node\n\t14.Delete the particular node\n\t15.Swapping\n\t");

		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:printf("Enter the number:");
			       scanf("%d",&num);
			       insert(num);
			       break;

			case 2:delete();
			       break;

			case 3:display();
			       break;

			case 4:count();
			       break;

			 case 5:printf("Enter the number to be search:");
				scanf("%d",&num);
				k=search(num);
				if(k==0)
					printf("Element not found\n");
				else
					printf("Element found at position-%d",k);
				break;

			case 6:delete_entire_list();
			       break;

			case 7:reverse_list();
			       break;

			case 8:printf("Enter the count:");
			       __fpurge(stdin);
			       scanf("%d",&c);
			       ptr=(int *)malloc(c*sizeof(int));
			       for(i=0;i<c;i++)
			       {
				       printf("Enter the array of elements:");
				       scanf("%d",&ptr[i]);
				}
			       create_list(ptr,c);
			       free(ptr);
			       break;

			case 9:printf("Enter the elements:");
			       scanf("%d %d",&num,&val);
			       add_before_node(num,val);
			       break;

			 case 10:printf("Enter the elements:");
                               scanf("%d %d",&num,&val);
                               add_after_node(num,val);
                               break;

			 case 11:printf("Enter the last node:");
				 scanf("%d",&num);
			       add_last_node(num);
				 break;

			 case 12:delete_last_node();
				 break;

			 case 13:delete_duplicate();
				 break;

			 case 14:printf("Enter the element to be deleted:");
				 __fpurge(stdin);
				 scanf("%d",&num);
				 delete_particular_node(num);
				 break;

			 case 15:printf("\nMenu\n\ta.Swap by data\n\tb.Swap by address\n\t");
				 printf("Enter the sub_option:");
				 __fpurge(stdin);
				 scanf("%c",&sub_opt);
				 switch(sub_opt)
				 {
					 case 'a':printf("Enter the elements to be swapped:");
						  __fpurge(stdin);
						  scanf("%d %d",&num,&val);
						  swap_data(num,val);
						  break;

					 case 'b':printf("Enter the elements to be swapped:");
                                                  __fpurge(stdin);
                                                  scanf("%d %d",&num,&val);
                                                  swap_address(num,val);
                                                  break;

				}
				break;

			 default:printf("Invalid option\n");
		}
	}
}


void insert(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory\n");
		return;
	}
	ptr->data=num;
	ptr->next=NULL;
	if(rear==NULL)//Queue is empty
	{
		ptr->prev=NULL;
		front=rear=ptr;
		return;
	}
	ptr->prev=rear;
	rear->next=ptr;
	rear=ptr;
}

void delete()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front==rear)//single node
	{
		free(front);
		rear=front=NULL;
		return;
	}
	else
	{
		temp=front;
		front=front->next;
		front->prev=NULL;
		free(temp);
	}
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
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}


void count()
{
	struct node *temp;
	int c=0;
	temp=front;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	printf("Count of the elements in the list-%d",c);
}

int search(int num)
{ 

	struct node *temp;
	int pos=0;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->next;
	}
}

void delete_entire_list()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(front!=NULL)
	{
		temp=front;
		front=front->next;
		free(temp);
	}
	front=rear=NULL;
	printf("Entire list is deleted\n");
}


void reverse_list()
{
	struct node *temp,*nxt,*cur;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	cur=front;
	while(cur!=NULL)
	{
		nxt=cur->next;
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		if(cur->prev==NULL)
			front=cur;
		cur=nxt;
	}
	rear=temp->next;
}

void create_list(int *iptr,int n)
{
	struct node *ptr;
	int i;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
                 if(ptr==NULL)
		{
			printf("Failed to allocate the memory\n");
			return;
		}
		ptr->data=iptr[i];
		ptr->next=NULL;
		if(rear==NULL)
		{
			ptr->prev=NULL;
			rear=front=ptr;
		}
		ptr->prev=rear;
		rear->next=ptr;
		rear=ptr;
	}
}

void add_before_node(int num,int val)
{
	struct node *ptr,*temp;
	temp=front;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node *)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
                   		printf("Failed to allocate the memory\n");
				return;
			}
			ptr->data=val;
			ptr->next=temp;
			ptr->prev=temp->prev;
			if(temp->prev==NULL)//first node
				front=ptr;
			else
				temp->prev->next=ptr;
			temp->prev=ptr;
			return;
		}
		temp=temp->next;
	}
	printf("Element not found\n");
}

void add_after_node(int num,int val)
{
	struct node *temp,*ptr;
	temp=front;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate memory\n");
				return;
			}
			ptr->data=val;
			ptr->next=temp->next;
			ptr->prev=temp;
			if(temp->next==NULL)
				rear=ptr;
			temp->next=ptr;
		}
		temp=temp->next;
	}
//	printf("Element not found\n");

}
 void add_last_node(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->next=NULL;
	if(rear==NULL)
	{
		ptr->prev=NULL;
		front=rear=ptr;
		return;
	}
	temp=front;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->prev=temp;
	temp->next=ptr;
	rear=ptr;
}
                   
void delete_last_node()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(front->next!=NULL)
		temp->prev->next=NULL;
	else
		front=rear=NULL;
	rear=temp->prev;
	free(temp);
	printf("Last node is deleted:");
}

void delete_duplicate()

	if(rear==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=front;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data==q->data)
			{
				temp=q;
				q->prev->next=q->next;
				if(q->next!=NULL)
					q->next->prev=q->prev;
				else
					rear=q->prev;
				q=q->prev;
				free(temp);
			}
		}
	}
}

void delete_particular_node(int num)
{
	struct node *temp,*p;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)
	{
		if(front->next==NULL)//single node
		{
			free(front);
			front=rear=NULL;
			return;
		}            
		temp=front;                 //first node
		front=temp->next;
		temp->next->prev=NULL;
		free(temp);
	}
	temp=front;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			if(temp->next!=NULL)
				temp->next->prev=temp->prev;
			else
				rear=temp->prev;
			temp->prev->next=temp->next;
			free(temp);
		}
		temp=temp->next;
	}
}
	
void swap_data(int num,int val)
{
        int temp;
        struct node *p1,*p2;
        if(rear==NULL)
        {
                printf("Queue is empty\n");
                return;
        }
        p1=p2=front;
        while(p1!=NULL)
        {
                if(p1->data==num)
                        break;
                p1=p1->next;
        }
        while(p2!=NULL)
        {
                if(p2->data==val)
                        break;
                p2=p2->next;
        }
        if((p1==NULL)||(p2==NULL))
        {
                printf("Data not found\n");
                return;
        }
        temp=p1->data;
        p1->data=p2->data;
        p2->data=temp;

}

void swap_address(int num,int val)
{
	struct node *p,*q,*temp;
	int pos1=0,pos2=0;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(num==val)
		return;
	p=q=front;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num)
			break;
		p=p->next;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==val)
			break;
		q=q->next;
	}
	if((p==NULL)||(q==NULL))
	{
		printf("Element not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}
	if(p->next!=q)//non adjacent nodes
	{
		temp=p->next;
		p->next=q->next;
		q->next=temp;

		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;

		q->next->prev=q;
		p->prev->next=p;

		if(p!=front)//if(q->prev!=NULL)
			q->prev->next=q;
		else
			front=q;
		if(p->next!=NULL)
			p->next->prev=p;
		else
			rear=p;
	}
	else       //adjacent nodes
	{
		p->next=q->next;
		q->next=p;

		q->prev=p->prev;
		p->prev=q;

		if(p!=front)//if(q->prev!=NULL)
                        q->prev->next=q;
                else
                        front=q;
                if(p->next!=NULL)
                        p->next->prev=p;
                else
                        rear=p;
	}
}







			
				





			
