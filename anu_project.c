//wap to perform the queue operation based on priority values

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
struct node
{
	int data;
	int prior;
	struct node *prev;
	struct node *next;
};



printf("vivek");
printf("science");
printf("sindhu");
printf("anu");



struct node *head=NULL;
void insert(int num,int priority);
void display();
void display1(int priority);
void delete_entire_list();
void delete_at_beginning();
void delete_priority(int priority);
void delete_data_priority(int num,int priority);
//void create_list(int* iptr,int* dptr,int n);
void create_list(int count);
void selection_sort_data();
int flag=0;
void main()
{
	int num,priority,count,opt,i,c;
	int *ptr1,*ptr2;
	char sub_opt;
	while(1) 
	{
		printf("\nMenu\n\t0.Exit\n\t1.Insert\n\t2.Display\n\t3.Delete entire list\n\t4.Delete\n\t5.Create the list\n\t6.Swapping\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:if(flag==0)
					delete_entire_list();	
				exit(0);
				
			case 1:printf("Enter the data:");
				scanf("%d",&num);
				printf("Enter the priority:");
				__fpurge(stdin);
				scanf("%d",&priority);
				insert(num,priority);
				break;
			
			case 2:printf("\n\ta.Display whole data and priority\n\tb.Display based on priority\n\t");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':display();
						break;
						
					case 'b':printf("Enter the priority to be display:");
						__fpurge(stdin);
						scanf("%d",&priority);
						display1(priority);
						break;
				}
				break;
				
			case 3:flag++;
				delete_entire_list();
				break;
			
			case 4:printf("\n\ta.Delete at beginning\n\tb.Delete based on priority\n\tc.Delete a particular data and priority\n\t:");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':delete_at_beginning();
						break;
					
					case 'b':printf("Enter the priority to be deleted:");
						__fpurge(stdin);
						scanf("%d",&priority);
						delete_priority(priority);
						break;
						
					case 'c':printf("Enter the data to be deleted:");
						__fpurge(stdin);
						scanf("%d",&num);
						printf("Enter its priority value:");
						__fpurge(stdin);
						scanf("%d",&priority);
						delete_data_priority(num,priority);
						break;
				}
				break;
						
			/*case 5:printf("Enter the count of elements in array:");
				__fpurge(stdin);
				scanf("%d",&c);
				for(i=0;i<c;i++);
				{
					ptr1=(int*)malloc(c*sizeof(int));
					printf("Enter the data in array:");
					__fpurge(stdin);
					scanf("%d",&ptr1[i]);
				}
				for(i=0;i<c;i++);
				{
					ptr2=(int*)malloc(c*sizeof(int));
					printf("Enter its priority value:");
					__fpurge(stdin);
					scanf("%d",&ptr2[i]);
				}
				create_list(ptr1,ptr2,c);
				break;*/
			
			case 5:printf("Enter the count to create the list:");
				scanf("%d",&count);
				create_list(count);
				break;
				
			case 6:printf("\n\ta.Selection sort by data without using priority\n\tb.Selection sort by data with using priority values\n\tc.Selection sort by link \n\t4.Selection_sort by links using priority values\n\t");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':selection_sort_data();
						break;
				}
				break;			
			default:printf("Invalid option:");
		}
		printf("\n......................................................................................\n");
	}
}

void insert(int num,int priority)
{
	struct node *ptr,*temp,*prv;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap:");
		exit(1);
	}
	ptr->data=num;
	ptr->prior=priority;
	if(head==NULL)//when list is empty
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	if(head->prior > priority)//when given priority is less then the existing priority ....elements inserted at starting
	{
		ptr->prev=head->prev;
		ptr->next=head;
		head->prev=ptr;
		head=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)//elements are inserted at middle .....even for same elements with similar priority
	{
		if(temp->prior > priority)
		{
			ptr->prev=temp->prev;
			ptr->next=temp;
			temp->prev->next=ptr;
			temp->prev=ptr;
			return;
		}
		prv=temp;
		temp=temp->next;
	}
	ptr->next=NULL;//highest priority elements are inserted at last
	ptr->prev=prv;
	prv->next=ptr;
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
		printf("DATA-%d  PRIORITY-%d\n",temp->data,temp->prior);
		temp=temp->next;
	}
}

void display1(int priority)
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
		if(temp->prior == priority)
			printf("DATA-%d  PRIORITY-%d\n",temp->data,temp->prior);
		temp=temp->next;
	}	
}

void delete_entire_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n:");
		return;
	}
	//temp=head;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	printf("\nEntire data is deleted:");
}

/*void delete_entire_list()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		free(temp);
		head=NULL;
	}
	printf("Entire data is deleted");
}*/

void delete_at_beginning()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	head=head->next;
	free(temp);
}

void delete_priority(int priority)
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior==priority)
		{
			p=temp;
			if(temp->prev==NULL)//single node
			{
				head=temp->next;
				//free(p);
				if(temp->next!=NULL)//first node in the list
				{
					temp->next->prev=NULL;
					//free(p);
				}
			}
			else 
			{
				temp->prev->next=temp->next;//last node
				//free(p);
				if(temp->next!=NULL)//middle nodes
				{
					temp->next->prev=temp->prev;
					//free(p);
				}
				
			}
			free(p);
		}
		temp=temp->next;
	}
}
		
			
/*void delete_priority(int priority)
{
	
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	if(temp->prior==priority)
	{
			p=temp;
			if(temp->prev==NULL)//single node
			{
				head=temp->next;
				if(temp->next!=NULL)//first node in the list
				{
					temp->next->prev=NULL;
				}
			}
			free(p);
			return;
	}
	while(temp!=NULL)
	{
		if(temp->prior == priority)
		{
			temp->prev->next=temp->next;//last node
			//free(p);
			if(temp->next!=NULL)//middle nodes
			{
				//temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				//free(p);
			}
			free(p);
			return;
		}
		temp=temp->next;
	}
}*/

void delete_data_priority(int num,int priority)
{
	struct node *temp,*p;
	if(head==NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		if((temp->data==num)&&(temp->prior==priority))
		{
			p=temp;
			if(temp->prev==NULL)//single node
			{
				head=temp->next;
				if(temp->next!=NULL)//first node in list
					temp->next->prev=temp->prev;
			}
			else
			{
				temp->prev->next=temp->next;//last node
				if(temp->next!=NULL)//middle nodes
					temp->next->prev=temp->prev;
			}
			free(p);
		}
		temp=temp->next;
	}
}
	
/*void create_list(int *iptr,int *dptr,int n)
{
	int i;
	struct node *temp,*ptr,*prv;
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap:");
			exit(1);
		}
		ptr->data=iptr[i];
		ptr->prior=dptr[i];
		if(head==NULL)//when list is empty
		{
			ptr->prev=NULL;
			ptr->next=NULL;
			head=ptr;
			return;
		}
		if(head->prior > dptr[i])//when given priority is less then the existing priority ....elements inserted at starting
		{
			ptr->prev=head->prev;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
			return;
		}
		temp=head;
		while(temp!=NULL)//elements are inserted at middle .....even for same elements with similar priority
		{
			if(temp->prior > dptr[i])
			{
				ptr->prev=temp->prev;
				ptr->next=temp;
				temp->prev->next=ptr;
				temp->prev=ptr;
				return;
			}
			prv=temp;
			temp=temp->next;
		}
		ptr->next=NULL;//highest priority elements are inserted at last
		ptr->prev=prv;
		prv->next=ptr;
	}
}*/
	
void create_list(int count)		
{

	printf("Hiiii");
	struct node *ptr,*temp,*pr;
	int i,num,priority;
	for(i=0;i<count;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory\n");
			exit(1);
		}
		printf("Enter the data:");
		__fpurge(stdin);
		scanf("%d",&num);
		printf("Enter its priority value:");
		__fpurge(stdin);
		scanf("%d",&priority);
		//insert(num,priority);
//	}
		ptr->data=num;
		ptr->prior=priority;
		if(head==NULL)//list is empty
		{
			ptr->prev=NULL;
			ptr->next=NULL;
			head=ptr;
			return;
		}
		if(head->prior > priority)
		{
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
			return;
		}
		temp=head;
		while(temp!=NULL)
		{
			if(temp->prior > priority)
			{
				ptr->prev=temp->prev;
				ptr->next=temp;
				temp->prev->next=ptr;
				temp->prev=ptr;
				return;
			}
			pr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		ptr->prev=pr;
		pr->next=ptr;			
	}
}

void selection_sort_data()
{
	struct node *p,*q,*temp;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->data > q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
				
				temp=p->prior;
				p->prior=q->prior;
				q->prior=temp;
			}
		}
	}
}

				
