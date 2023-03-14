#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void add_at_beginning(int num);
void delete_at_beginning();
void display();
void count();
int search(int num);
void add_last_node(int num);
void delete_last_node();
void delete_entire_list();
void add_after_node(int num,int val);
void create_list(int *iptr,int n);
void add_before_node(int num,int val);
void reverse_list();
void swap_data(int num,int val);
void swap_address(int num,int val);
void delete_duplicate_node();
void delete_particular_node(int num);
void selection_sort_data();
void selection_sort_address();
void main()
{
	int num,val,opt,k,*ptr,i,c;
	char sub_opt;
	while(1)
	{
		printf("\n\n0.exit\n\n1.Add at beginning\n\n2.Delete at beginning\n\n3.Display\n\n4.Count\n\n5.Search\n\n6.Add node at last\n\n7.Delete node at last\n\n8.Delete the entire list\n\n9.Add after a node\n\n10.Create the list\n\n11.Add before the node\n\n12.Reverse the list\n\n13.Swapping\n\n14.Delete the duplicate node\n\n15.Delete particular node\n\n16.Selection sort\n\n");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:printf("Enter the number:");
			       scanf("%d",&num);
			       add_at_beginning(num);
			       break;

			case 2:delete_at_beginning();
			       break;

			case 3:display();
			       break;
			case 4:count();
			       break;

			case 5:printf("Enter the number to be searched:");
			       scanf("%d",&num);
			       k=search(num);
			       if(k==0)
				       printf("Element not found\n");
			       else
				       printf("Element found at position-%d",k);

			       break;

			case 6:printf("Enter the number:");
			       scanf("%d",&num);
			       add_last_node(num);
			       break;

			case 7:delete_last_node();
			       break;

			case 8:delete_entire_list();
			       break;

			case 9:printf("Enter the elements :");
			       scanf("%d %d",&num,&val);
			       add_after_node(num,val);
			       break;

			case 10:printf("Enter the count:");
				scanf("%d",&c);
				ptr=(int*)malloc(c*sizeof(int));
				for(i=0;i<c;i++)
				{
					printf("Enter the array of elements:");
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,c);
				free(ptr);
				break;

			case 11:printf("Enter the elements:");
				scanf("%d %d",&num,&val);
				add_before_node(num,val);
				break;

			case 12:reverse_list();
				break;

			case 13:printf("\nMenu\n\ta.Swap by data\n\tb.Swap by address\n\t");
				printf("Enter the sub_opt:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("Enter the elements to be swapped:");
						 __fpurge(stdin);
						 scanf("%d %d",&num,&val);
						 swap_data(num,val);
						 break;

					case 'b': printf("Enter the elements to be swapped:");
						  __fpurge(stdin);
						  scanf("%d %d",&num,&val);
						  swap_address(num,val);
						  break;
					default:printf("Invalid suboption\n");
				}
				break;

			case 14:delete_duplicate_node();
				break;

			case 15:printf("Enter the element to be deleted:");
				scanf("%d",&num);
				delete_particular_node(num);
				break;

			case 16:printf("\nMenu\n\ta.Selection sort by data\n\tb.Selection sort by address\n\t");
				printf("Enter the sub_opt:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a': selection_sort_data();
						  break;

					case 'b': selection_sort_address();
						  break;
					default:printf("Invalid suboption\n");
				}
				break;


			default:printf("Invalid option:");
		}
		printf("\n.......................................\n");
	}
}

void add_at_beginning(int num)
{
	struct node *ptr;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->prev=NULL;
	ptr->next=head;
	if(head!=NULL)
		head->prev=ptr;
	head=ptr;
}


void delete_at_beginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	head=head->next;//next node address
	head->prev=NULL;//in next node prev updating null
	free(temp);
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
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

void count()
{
	struct node *temp;
	int c=0;
	/*if(head==NULL)
	  {
	  printf("List is empty\n");
	  return;
	  }*/
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;

	}
	printf("count of elements in list %d",c);
}	

int search(int num)
{
	struct node *temp;
	int pos=0;
	if(head==NULL)
	{
		printf("List is empty\n");
		return pos;
	}
	temp=head;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data==num)
			return pos;
		temp=temp->next;
	}
}

void add_last_node(int num)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->next=NULL;
	if(head==NULL)
	{
		ptr->prev=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ptr->prev=temp;
	temp->next=ptr;
}

void delete_last_node()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(head->next!=NULL)
		temp->prev->next=NULL;//for multiple node
	else
		head=NULL;//for single node
	free(temp);
}

void delete_entire_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	/*if(head->next!=NULL)
	  { printf("Enter the elements to be swapped:");
	  scanf("%d %d",&num,&val);
	  swap_address(num,val);
	  break;
	  head=NULL;
	  free(temp);
	  }*/
	while(temp!=NULL)
	{
		temp=temp->next;
		free(temp);
		head=NULL;
	}
}

void add_after_node(int num,int val)
{
	struct node *temp,*ptr;
	temp=head;
	while(temp->next!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory\n");
				return;
			}
			ptr->data=val;
			ptr->next=temp->next;
			temp->next=ptr;
			ptr->prev=temp;
		}
		temp=temp->next;
	}
}

void create_list(int *iptr,int n)
{
	int i;
	struct node *ptr,*prev,*start=NULL,*temp;
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
		if(start==NULL)
		{
			ptr->prev=NULL;
			start=ptr;
			prev=ptr;//prev stores the first node address
		}
		else
		{
			ptr->prev=prev;//prev value is updated in ptr of prev.
			prev->next=ptr;
			prev=ptr;
		}
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=start;
	start->prev=temp;
}

void add_before_node(int num,int val)
{
	struct node *ptr,*temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate memory in heap\n");
				return;
			}
			ptr->data=val;
			ptr->prev=temp->prev;//updating the ptr previous value 
			ptr->next=temp;//updating the ptr of next with temp
			if(temp->prev==NULL)//if it is first node
				head=ptr;
			else
				temp->prev->next=ptr;//creating link with ptr in before node
			temp->prev=ptr;//creating link with ptr in after the node
			return;
		}
		temp=temp->next;
	}
	printf("Element not found\n");
}

void reverse_list()
{
	struct node *temp,*nxt,*cur;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	cur=head;
	while(cur!=NULL)
	{
		nxt=cur->next;
		temp=cur->prev;
		cur->prev=cur->next;
		cur->next=temp;
		if(cur->prev==NULL)
			head=cur;
		cur=nxt;
	}
}


void swap_data(int num,int val)
{
	int temp;
	struct node *p1,*p2;
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
	int pos1=0,pos2=0;
	struct node *p,*q,*temp;
	if(num==val)
		return;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
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
	if((p==NULL)&&(q==NULL))
	{
		printf("Element is not found\n");
		return;
	}
	if(pos1>pos2)
	{
		temp=p;
		p=q;
		q=temp;
	}

	if(p->next!=q)//Non adjacent nodes
	{
		temp=p->next;
		p->next=q->next;
		q->next=temp;

		temp=p->prev;
		p->prev=q->prev;
		q->prev=temp;

		p->prev->next=p;
		q->next->prev=q;
		if(p!=head)
			q->prev->next=q;
		else
			head=q;
		if(p->next!=NULL)
			p->next->prev=p;
	}
	else
	{
		p->next=q->next;
		q->next=p; 

		q->prev=p->prev;
		p->prev=q;
		if(p!=head)
			q->prev->next=q;
		else
			head=q;
		if(p->next!=NULL)
			p->next->prev=p;
	}
}

void delete_duplicate_node()
{
	struct node *p,*q,*temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data==q->data)
			{
				temp=q;
				q->prev->next=q->next;
				if(q->next!=NULL)
					q->next->prev=q->prev;
				q=q->prev;
				free(temp);
			}
		}
	}
}

void delete_particular_node(int num)
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num)//first node
	{
		if(head->next==NULL)//for single node
		{
			free(head);
			head=NULL;
			return;
		}
		temp=head;
		head=head->next;//updating the head value with next node
		head->prev=NULL;//updated first node should contain null in prev
		free(temp);
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			temp->prev->next=temp->next;//for last node
			if(temp->next!=NULL)//middle node
				temp->next->prev=temp->prev;
			free(temp);
			return;
		}
		temp=temp->next;
	}

	//	printf("Element not found\n");
}

void selection_sort_data()
{
	struct node *p,*q;
	int temp;
	for(p=head;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

void selection_sort_address()
{
	struct node *p,*q,*temp;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				if(p->next!=q)//Non adjacent nodes
				{

					temp=p->next;
					p->next=q->next;
					q->next=temp;

					temp=p->prev;
					p->prev=q->prev;
					q->prev=temp;

					p->prev->next=p;
					q->next->prev=q;
					if(p!=head)
						q->prev->next=q;
					else
						head=q;
					if(p->next!=NULL)
						p->next->prev=p;
				}
				else
				{
					p->next=q->next;
					q->next=p;

					q->prev=p->prev;
					p->prev=q;
					if(p!=head)
						q->prev->next=q;
					else
						head=q;
					if(p->next!=NULL)
						p->next->prev=p;
					//     q->prev=NULL;
				}
				temp=p;
				p=q;
				q=temp;

			}
		//	temp=p;
                  //              p=q;
                    //            q=temp;

		}
	}
}

