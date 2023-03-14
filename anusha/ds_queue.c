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
void delete();
void display();
int count();
int search(int num);
void delete_entire_queue();
void delete_particular_node();
void reverse_queue();
void create_queue(int *dptr,int n);
void swap_data(int num1,int num2);
void swap_link(int num1,int num2);
void main()
{
	int num,opt,k,s,*ptr,i,cou,num1,num2;
	char sub_opt;
	while(1)
	{
		printf("\n\tMenu\n\t0.exit\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Count\n\t5.Search\n\t6.Delete entire Queue\n\t7.Delete particular node\n\t8.Reverse_queue\n\t9.Create Queue\n\t10.Swapping\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			       	break;

			case 1:printf("Enter the number to be inserted:");
			       scanf("%d",&num);
			       insert(num);
			       break;

			case 2:delete();
			       break;
			case 3:display();
			       break;
			case 4:k=count();
			       printf("Count of the elements in Queue-%d",k);
			       break;
			case 5:printf("Enter the element to be searched:");
			       scanf("%d",&num);
			       s=search(num);
			       if(s==0)
					printf("Element not found in Queue\n");
			       else
				       printf("Element found at %d postion",s);
				break;
			case 6:delete_entire_queue();
			       break;
			case 7:printf("Enter the element to be delete:");
			       scanf("%d",&num);
			       delete_particular_node(num);
			       break;
			case 8:reverse_queue();
			       break;
			case 9:printf("Enter the count:");
			       __fpurge(stdin);
			       scanf("%d",&cou);
				ptr=(int *)malloc(1*sizeof(int));
				for(i=0;i<cou;i++)
				{
					printf("Enter the element:");
					__fpurge(stdin);
					scanf("%d",&ptr[i]);
				}
			       create_queue(ptr,cou);
			       break;
			case 10:printf("\n\ta.Swap by data\n\tSwap by links\n\t");
				printf("Enter the sub_opt:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("Enter the elements to be swapped:");
						__fpurge(stdin);
						 scanf("%d %d",&num1,&num2);
						 swap_data(num1,num2);
						 break;
					case 'b':printf("Enter the elements to be swapped:");
                                                 scanf("%d %d",&num1,&num2);
                                                 swap_link(num1,num2);
                                                 break;
					default:printf("Invalid sub_option:");
				}
				break;



			default:printf("Invalid option\n");
		}
		printf("\n.............................................................................\n");
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
		front=rear=ptr;
		return;
	}
	rear->link=ptr;
	rear=ptr;
}

void delete()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	else if(front->link==NULL)
	{
		free(front);
		front=rear=NULL;
		return;
	}
	else
	{
		temp=front;
		front=front->link;
		free(temp);
	}
}

void display()
{
	struct node *temp;
	if(front==NULL)
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

int count()
{
	int c=0;
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=front;
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
	if(rear==NULL)
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
		temp=temp->link;
	}
}

void delete_entire_queue()
{
	struct node *temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	while(front!=NULL)
	{
		temp=front;
		front=front->link;
		free(temp);
	}
	front=rear=NULL;
	return;
}

void delete_particular_node(int num)
{
	struct node *prev,*cur,*temp;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(front->data==num)//if deleted element is first node
	{
		if(front->link==NULL)//if element is first and single node in queue
		{
			free(front);
			front=NULL;
			return;
		}
		else{			//element is first node but it contains multiple node in queue
			temp=front;
			front=temp->link;
			free(temp);
			return;
		}
	}
	prev=front;
	cur=front->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}
		if(cur==rear)
			rear=prev;
	
	prev=cur;
	cur=cur->link;
	}
	printf("Element not found\n");
}

void reverse_queue()
{
	struct node *prev,*cur,*next,*temp;
	if(rear==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	prev=NULL;
	cur=front;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
/*	temp=rear;//first method
	rear=front;
	front=temp;*/

	rear=front;
	front=temp;

}

void create_queue(int *dptr,int n)
{
	struct node *ptr;
	int i;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		  if(ptr==NULL)
	          {
        	        printf("Failed to allocate the memory\n");
              		 exit(1);
       		  }

		ptr->data=dptr[i];
		ptr->link=NULL;
		if(rear==NULL)//when no elements are present in queue earlier
		{
			rear=front=ptr;
			return;
		}
		rear->link=ptr;
		rear=ptr;
	}
}
void swap_data(int num1,int num2)
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
		if(p1->data==num1)
			break;
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		if(p2->data==num2)
			break;
		p2=p2->link;
	}
	if((p1==NULL)||(p2==NULL))
	{
		printf("Data is not found\n");
		return;
	}
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}

void swap_link(int num1,int num2)
{
	int pos1=0,pos2=0;
	struct node *p,*q,*r,*s,*temp;
	if(num1==num2)
		return;
	if(front==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	p=q=front;//p and q are current pointers
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num1)
			break;
		r=p;
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)
			break;
		s=q;
		q=q->link;
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
		temp=r;
		r=s;
		s=temp;
	}
	if(p->link!=q)//non adjacent nodes
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=front)
			r->link=q;
		else
			front=q;
			s->link=p;
		if(q==rear)
			rear=p;
	}
	else  //for adjacent nodes
	{
		p->link=q->link;
		q->link=p;
		if(p!=front)
			r->link=q;
		else
			front=q;
		if(q==rear)
			rear=p;
	}
}
		
		
	
