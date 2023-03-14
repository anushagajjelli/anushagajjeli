//wap to perform the single linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
//....................................function declarations.......................................
void add_at_beginning(int num);
void delete_at_beginning();
void display(int num);
int count(int num);
int search(int num);
void delete_entire_list();
void add_node_at_last(int num);
void delete_last_node();
void add_after_a_node(int num,int val);
void delete_particular_node(int num);
void add_before_a_node(int num,int val);
void reverse_the_list();
void create_list(int *dptr,int n);
void swap_by_data(int num1,int num2);
void swap_by_link(int num1,int num2);
void delete_duplicate_node();
//...................................struct datatype..............................................
struct node
{
	int data;
	struct node* link;
};
//..................................struct global variable.........................................
struct node* head=NULL;
//.......................................main function.............................................
void main()
{
	int num,pos,opt,k,val,c,i,num1,num2;
	int* ptr;
	char sub_opt;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Add at beginning\n\t2.Delete at beginning\n\t3.Display\n\t4.Count\n\t5.Search\n\t6.Delete the entire list\n\t7.Add node at last\n\t8.Delete node at last\n\t9.Add node after a node\n\t10.Delete the particular node in the list\n\t11.Add a node before a node\n\t12.Reverse the list\n\t13.Create the list\n\t14.Swapping\n\t15.Delete Duplicate elements in the list\t\n");
		printf("Enter the option to perform:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
				break;
				
			case 1:printf("Enter the number to be add:");
				scanf("%d",&num);
				add_at_beginning(num);
				break;
				
			case 2:delete_at_beginning();
				break;
				
			case 3://printf("Perform the Display function\n");
				display(num);
				break;
			
			case 4://printf("Count of the data\n");
				k=count(num);
				printf("count of elements in the list -%d",k);
				break;
				
			case 5:printf("Enter the element to be searched:");
				scanf("%d",&num);
				pos=search(num);
				if(pos==0)
				{
					printf("element is not found in the list\n");
				}
				 else
				{
					printf("element is  found at :%d position",pos);
				}
				break;
				
			case 6:delete_entire_list();
				break;
				
			case 7:printf("Enter the element:");
				scanf("%d",&num);
				add_node_at_last(num);
				break;
				
			case 8:delete_last_node();
				break;
			
			case 9:printf("Enter the num and val inputs:");
				scanf("%d %d",&num,&val);
				add_after_a_node(num,val);
				break;
				
			case 10:printf("enter the data to delete the particular node:");
				scanf("%d",&num);
				delete_particular_node(num);
				break;
			
			case 11: printf("Enter the num and val inputs:");
				scanf("%d %d",&num,&val);
				add_before_a_node(num,val);
				break;
				
			case 12:reverse_the_list();
				break;
				
			case 13:
				printf("Enter the count:");
				//__fpurge(stdin);
				scanf("%d",&c);
				ptr=(int *)malloc(c*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap\n");
					exit(1);
				}
				for(i=0;i<c;i++)
				{
					printf("Enter the input\n");
					//__fpurge(stdin);
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,c);
				free(ptr);
				break;
			
			case 14:printf("\n\ta.Swap by data \n\tb.Swap by link\n\t");
				printf("Enter the option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a': printf("Enter the elements to be swapped:");
						scanf("%d %d",&num1,&num2);
						swap_by_data(num1,num2);
						break;
					
					case 'b':printf("Enter the elements to be swapped:");
						scanf("%d %d",&num1,&num2);
						swap_by_link(num1,num2);
						break;	
					
					default:printf("Entered the invalid sub option\n");
				}
				break;
			
			case 15:delete_duplicate_node();
				break;
			default:printf("Invalid option\n");
		}
		printf("\n....................................................\n");
	}
}
//..............................................Function Definitions...........................................................
//.....................................Function defintion of add the element at beginning.......................................
void add_at_beginning(int num)
{
	struct node *ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap\n");
		exit(1);
	}
	ptr->data=num;
	ptr->link=head;
	head=ptr;
}

//.....................................Function definition of delete the element at beginning.........................................
void delete_at_beginning()
{
	struct node* temp;
	int x;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	head=head->link;
	x=temp->data;
	free(temp);
	printf("Deleted element is %d\n",x);
}
//.......................................Function definition of Display function..................................................
void display(int num)
{
	struct node* temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->link;
	}
}
//.......................................Function definition of Count the no.of elements in the list......................................
int count(int num)
{
	struct node* temp;
	int c=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->link;
	}
	return c;
}
//...........................................Function definition of Search the element in the given list.......................................
int search(int num)
{
	struct node * temp;
	int k=0,s=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		//return ;
	}
	temp=head;
	//printf("%d",temp);
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			//printf("position is at -%d\n",pos);
			s++;
			return s+k;
		}
		temp=temp->link;
		k++;
			
	}
	if(s==0)
		return 0;
	
	//return pos+k;
}

//...............................................Function definition of Delete the entire list.......................................................
void delete_entire_list()
{
	struct node* temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		head=head->link;
		free(temp);
		temp=head;
	}
	printf("Entire data in the list is deleted\n");
}	


void add_node_at_last(int num)
{
	struct node* temp;
	struct node* ptr=(struct node*)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->link=NULL;
	if(head==NULL)//when list is empty and new node is added
	{
		head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=NULL)//when list contains nodes
	{
		temp=temp->link;
	}
	temp->link=ptr;
}
	
void delete_last_node()
{
	struct node *prev,*cur;//prev->previous node and cur->current node
	if(head==NULL)//when list is empty
	{
		printf("List is empty\n");
		return;
	}
	if(head->link==NULL)//when list contains only a single node
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur->link!=NULL)//when list contains more nodes
	{
		prev=cur;
		cur=cur->link;
	}
	free(cur);//deallocating the last node
	prev->link=NULL;//updating the null to the previous node(last to 2nd node)
}


void add_after_a_node(int num,int val)
{
	struct node* temp,* ptr;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory in heap\n");
				exit(0);
			}
			ptr->data=val;
			ptr->link=NULL;
			ptr->link=temp->link;
			temp->link=ptr;
			return;
		}
		temp=temp->link;
	}
	printf("Element is not found\n");
}

void delete_particular_node(int num)
{
	struct node* prev,*cur;
	if(head==NULL)
	{
	
		printf("List id empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==NULL)//when only single node is present in the list
		{
			free(head);
			head=NULL;
			return;
		}
		cur=head;
		head=head->link;
		free(cur);
		head==NULL;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			prev->link=cur->link;
			free(cur);
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("Element is not found\n");
}

void add_before_a_node(int num,int val)
{
	struct node *prev,*cur,*ptr;
	if(head==NULL)//list is empty
	{
		printf("List is empty\n");
		return;
	}
	if(head->data==num);
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory in heap\n");
				exit(1);
			}
		ptr->data=val;
		ptr->link=head;
		head=ptr;
		return;
	}
	prev=head;
	cur=head->link;
	while(cur!=NULL)
	{
		if(cur->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap\n");
					exit(1);
				}
			ptr->data=val;
			ptr->link=cur;
			prev->link=ptr;
			//cur=ptr;
			return;
		}
	}
	prev=cur;
	cur=cur->link;
	printf("Element is not found\n");
}	

void reverse_the_list()
{
	struct node *prev,*cur,*next;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	prev=NULL;
	cur=head;
	while(cur!=NULL)
	{
		next=cur->link;
		cur->link=prev;
		prev=cur;
		cur=next;
	}
	head =prev;
}

void create_list(int *dptr,int n)
{
	int i;
	struct node *ptr=NULL,*prev,*start=NULL,*temp;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory\n");
			exit(2);
		}
		ptr->data=dptr[i];
		ptr->link=NULL;
		if(start==NULL)
			start=ptr;
		else
			prev->link=ptr;
		prev=ptr;
	}
	if(head==NULL)
	{
		head=start;
		return;
	}
	temp=head;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=start;
}

void swap_by_data(int num1,int num2)
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
		printf("Data not found\n");
		return;
	}
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}
			
void swap_by_link(int num1,int num2)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(num1==num2)//if both numbers are equal then no need to swap
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
		if(p->data==num1)
			break;
		r=p;              //p-points current node and r-points the previous node of p
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)	
			break;
		s=q;             //q-points the current node and s-points the previous node of q
		q=q->link;
	}
	if((p==NULL)||(q==NULL))
	{
		printf("Element not found\n");
		return;
	}
	if(pos1>pos2)//if p position is greater than q then swap their positions
	{
		temp=p;
		p=q;
		q=temp;
		temp=r;
		r=s;
		s=temp;
	}
	if(p->link!=q)//for non-adjacent nodes
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)// if p is not the first node
			r->link=q;
		else         //if p is first node then else part executes
			head=q;
		s->link=p;
		return;
	}
	else   
	{                           //for adjacent nodes of p and q then no need of s 
		p->link=q->link;
		q->link=p;
		if(p!=head)   //if p is not the first node
			r->link=q;
		else		//if p is first node
			head=q;
		return;
	}
}

void delete_duplicate_node()
{
	struct node *p,*q,*s;
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
