//wap to perform the single circular linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	struct node *link;
};

struct node *head=NULL;
void add_at_beg(int num);
void delete_at_beg();
void display();
void count();
int search(int num);
void add_node_last(int num);
void delete_node_last();
void delete_entire_list();
void delete_duplicate_node();
void create_list(int *iptr,int n);
void reverse_list();
void delete_particular_node(int num);
void add_after_node(int num,int val);
void add_before_node(int num,int val);
void swap_data(int num,int val);
void swap_link(int num,int val);
int flag=0;
void main()
{
	int opt,k,c,i,val,num;
	char sub_opt;
	while(1)
	{
		printf("\nMenu\n\n\t0.exit\n\n\t1.Add at beginning\n\n\t2.Delete at beginning\n\n\t3.Display\n\n\t4.Count\n\n\t5.Search\n\n\t6.Add node at last\n\n\t7.Delete node at last\n\n\t8.Delete entire list\n\n\t9.Delete duplicate node\n\n\t10.Create the list\n\n\t11.Reverse list\n\n\t12.Delete particular node\n\n\t13.Add after node\n\n\t14.Add before node\n\n\t15.Swapping\n\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:flag++;
			       printf("Enter the number:");
			       scanf("%d",&num);
			       add_at_beg(num);
			       break;

		        case 2:delete_at_beg();
				break;

			case 3:display();
			       break;
			case 4:count();
			       break;
			case 5:printf("Enter the element to be searched:");
			       scanf("%d",&num);
			       k=search(num);
			       if(k==0)
				       printf("Element not found\n");
			       else
				       printf("Element found at position-%d",(flag-k)+1);
			       break;
			case 6:flag++;
			       printf("Enter the element at last:");
			       __fpurge(stdin);
			       scanf("%d",&num);
			       add_node_last(num);
			       break;

			case 7:delete_node_last();
			       break;

			case 8:delete_entire_list();
			       break;

			case 9:delete_duplicate_node();
			       break;

			case 10:{
					
					int i;
					int *ptr;
					printf("Enter the count:");
					scanf("%d",&c);
					ptr=(int *)malloc(c*sizeof(int));
					if(ptr==NULL)
					{
						printf("Failed to allocate the memory\n");
						exit(1);
					}
					for(i=0;i<c;i++)
					{
						printf("Enter the array of elements:");
						scanf("%d",&ptr[i]);
					}
					create_list(ptr,c);
					//	free(ptr);
					break;
				}

			case 11:reverse_list();
				break;

			case 12:printf("Enter the data to be deleted:");
				scanf("%d",&num);
				delete_particular_node(num);
				break;

			case 13:printf("Enter the data:");
				__fpurge(stdin);
				scanf("%d",&num);
				printf("Enter the new node to be added:");
				__fpurge(stdin);
				scanf("%d",&val);
				add_after_node(num,val);
				break;
				
			case 14:printf("Enter the data:");
				__fpurge(stdin);
				scanf("%d",&num);
				printf("Enter the new node to be added:");
				__fpurge(stdin);
				scanf("%d",&val);
				add_before_node(num,val);
				break;
			
			case 15:printf("Menu\n\ta.Swap by data\n\tb.Swap by links\n\t");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("Enter the elements to be swapped:");
						scanf("%d %d",&num,&val);
						swap_data(num,val);
						break;
						
					case 'b':printf("Enter the elements to be swapped:");
						scanf("%d %d",&num,&val);
						swap_link(num,val);
						break;
				}
				break;
			default:printf("Invalid option:");
		}
	}
}

void add_at_beg(int num)
{
	struct node *temp;
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	if(head==NULL)
	{
		head=ptr->link=ptr;
		return;
	}
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	ptr->link=head;
	head=temp->link=ptr;


}

void delete_at_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=head->link;
	free(head);
	head=temp->link;
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp=head;
	do{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
	while(temp!=head);
}

void count()
{
	struct node *temp;
	int c=0;
	temp=head;
	do{
		c++;
		temp=temp->link;
	}
	while(temp!=head);
	printf("Count of the elements in the list-%d\n",c);
}


int search(int num)
{
	int pos=0;
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return pos;
	}
	temp=head;
	/*	while(temp!=head)
		{
		pos++;
		if(temp->data==num)
		return pos;
		temp=temp->link;
		}*/

	do{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->link;
	}
	while(temp!=head);
}

void add_node_last(int num)
{
	struct node *ptr,*temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	if(head==NULL)
	{
		head=ptr->link=ptr;
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	ptr->link=head;
	temp->link=ptr;
}

void delete_node_last()
{
	struct node *temp,*prev;
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	temp=head->link;
	while(temp->link!=head)
	{
		prev=temp;
		temp=temp->link;
	}
	prev->link=head;
	free(temp);
}

void delete_entire_list()
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==head)//single node
	{
		free(head);
		head=NULL;
		return;
	}
	p=head;
	while(head->link!=p)
	{
		temp=head;
		head=head->link;
		free(temp);
	}
	temp=head;
	free(temp);
	head=NULL;
	printf("Entire data is deleted\n");
}


void delete_duplicate_node()
{
	struct node *p,*q,*s;
	for(p=head;p->link!=head;p=p->link)
	{
		for(s=p,q=p->link;q!=head;s=q,q=q->link)
		{
			if(p->data==q->data)
			{
				s->link=q->link;//updating the head value in s link
				free(q);
				q=s;
			}
			//	q=s;
		}
	}
}

void create_list(int *dptr,int n)
{
	int i;
	struct node *ptr,*cur;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate memory in heap:");
			exit(2);
		}
		ptr->data=dptr[i];
		if(head==NULL)
		{
			head=ptr->link=ptr;
			continue;
		}
		else
		{
			cur=head->link;
			while(cur->link!=head)
			{
				cur=cur->link;
			}
			ptr->link=cur->link;
			cur->link=ptr;

		}
	}
}

void reverse_list()
{
	struct node *next,*prev,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=head;
	cur=head;
	while(cur->link!=head)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	next=cur->link;
	cur->link=prev;
	next->link=cur;
	head=cur;
}


void delete_particular_node(int num)
{
	struct node *temp,*cur;
	if(head==NULL)
	{
		printf("List is empty\n:");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)//single node
		{
			free(head);
			head=NULL;
			return;
		}
		temp=head;
		head=head->link;   //first node
		//	head->prev=NULL;
		free(temp);
		return;
	}
	cur=head;
	temp=head->link;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			cur->link=temp->link;//middle nodes
			if(temp->link==head)
				cur->link=head;//last node
			free(temp);
			return;
		}
		cur=temp;
		temp=temp->link;
	}
	printf("Element not found\n");
}

void add_after_node(int num,int val)
{
	struct node *temp,*ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}

	temp=head;
	do
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate memory in heap\n");
				exit(2);
			}
			ptr->data=val;
			ptr->link=temp->link;
			temp->link=ptr;
		}
		temp=temp->link;
	}
	while(temp!=head);


}

void add_before_node(int num,int val)
{
	struct node *temp,*ptr,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	if(head->data==num)
	{
		//if(head->link==head)
		//{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory in heap\n");
				return;
			}
			ptr->data=val;
			ptr->link=head->link;
			head->link=ptr;
			head=ptr;
			return;
		//}
	}
	cur=head;
	temp=head->link;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{				
				printf("Failed to allocate the memory in heap\n");
				return;
			}
			ptr->data=val;
			ptr->link=temp;
			cur->link=ptr;
			return;
		}
		cur=temp;
		temp=temp->link;
	}
}

void swap_data(int num,int val)
{
	struct node *p1,*p2;
	int temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p1=p2=head;
	while(p1!=NULL)
	{
		if(p1->data==num)
			break;
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(p2->data==val)
			break;
		p2=p2->link;
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

void swap_link(int num,int val)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0,f1=0,f2=0;
	if(num==val)
		return;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
	do{
		pos1++;
		if(p->data==num)
		{
			f1=1;
			break;
		}
		r=p;
		p=p->link;
	}
	while(p!=head);
	
	do
	{
		pos2++;
		if(q->data==val)
		{
			f2=1;
			break;
		}
		s=q;
		q=q->link;
	}
	while(q!=head);
	
	if((f1!=1)||(f2!=1))
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
	
	if(p->link!=q)//non adjacent nodes
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)
			r->link=q;
		else
		{
			temp=head;
			while(temp->link!=head)//to access the last node....updating the last node when head value changes
				temp=temp->link;
			head=q;
			temp->link=head;
		//	return;
		}
		s->link=p;		
	}
	else         //adjacent nodes
	{
		p->link=q->link;
		q->link=p;
		if(p!=head)
			r->link=q;
		else
		{
			temp=head;
			while(temp->link!=head)//to access the last node....updating the last node when head value changes
				temp=temp->link;
			head=q;
			temp->link=head;
		//	return;
		}
	}
}
