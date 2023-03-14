//wap to perform the queue operation based on priority values

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
//..................................................Structure Datatype.......................................................
struct node
{
	int data;
	int prior;
	struct node *prev;
	struct node *next;
};
//...................................................Structure Global Variable................................................
struct node *head=NULL;
//...................................................Function Declarations....................................................
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
void selection_sort_data1(int priority);
void selection_sort_address();
void selection_sort_address_priority(int priority);
int flag=0;//global variable
//...................................................Main Function....................................................................
void main()
{
	int num,priority,count,opt,i,c;
	int *ptr1,*ptr2;
	char sub_opt;
	while(1) 
	{
		printf("\nMenu\n\t0.Exit\n\t1.Insert\n\t2.Display\n\t3.Delete entire list\n\t4.Delete\n\t5.Create the list\n\t6.Selection sort\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:if(flag==0)
					delete_entire_list();	//function call delete entire list
				exit(0);
				
			case 1:printf("Enter the data:");
				scanf("%d",&num);
				printf("Enter the priority:");
				__fpurge(stdin);
				scanf("%d",&priority);
				insert(num,priority);//function call of insert
				break;
			
			case 2:printf("\n\ta.Display whole data and priority\n\tb.Display based on priority\n\t");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':display();                     //Function call display
						break;
						
					case 'b':printf("Enter the priority to be display:");
						__fpurge(stdin);
						scanf("%d",&priority);
						display1(priority);          //Function call of display function based on priority
						break;
				}
				break;
				
			case 3:flag++;
				delete_entire_list();           //Function call of delete entire list
				break;
			
			case 4:printf("\n\ta.Delete at beginning\n\tb.Delete based on priority\n\tc.Delete a particular data and priority\n\t:");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':delete_at_beginning();             //Function call of delete at beginning function
						break;
					
					case 'b':printf("Enter the priority to be deleted:");
						__fpurge(stdin);
						scanf("%d",&priority);
						delete_priority(priority);           //Function call of Delete function based on priority
						break;
						
					case 'c':printf("Enter the data to be deleted:");
						__fpurge(stdin);
						scanf("%d",&num);
						printf("Enter its priority value:");
						__fpurge(stdin);
						scanf("%d",&priority);
						delete_data_priority(num,priority);         //Function call of Delete data and priority function
						break;
				}
				break;
						
			/*case 5:printf("Enter the count of elements in array:");
				__fpurge(stdin);
				scanf("%d",&c);
					ptr1=(int*)malloc(c*sizeof(int));
					ptr2=(int*)malloc(c*sizeof(int));
				for(i=0;i<c;i++)
				{
					printf("%d\n",i);
					printf("Enter the data in array:");
					__fpurge(stdin);
					scanf("%d",&ptr1[i]);
					printf("Enter its priority value:");
					__fpurge(stdin);
					scanf("%d",&ptr2[i]);
				}
				create_list(ptr1,ptr2,c);
				break;*/
			
			case 5:printf("Enter the count to create the list:");
				scanf("%d",&count);
				create_list(count);            //Function call of Create list 
				break;
				
			case 6:printf("\n\ta.Selection sort by data without using priority\n\tb.Selection sort by data with using priority values\n\tc.Selection sort by link \n\td.Selection_sort by links using priority values\n\t");
				printf("Enter the sub_option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':selection_sort_data();             //Function call of selection sort based on data
						break;

					case 'b':printf("Enter the priority:");
						 scanf("%d",&priority);
						 selection_sort_data1(priority);       //Function call of Selection sort of data based on priority
						 break;

					case 'c':selection_sort_address();          //Function call of selection sort by address
						 break;

					case 'd':printf("Enter the priority for selection sort:");
						 scanf("%d",&priority);
						 selection_sort_address_priority(priority);            //Function call of selection sort of address based on priority
						 break;
					default:printf("Enter the valid sub option\n");

				}
				break;			
			default:printf("Invalid option:");
		}
		printf("\n......................................................................................\n");
	}
}

//..........................................................Function defintion of Insert.............................................................
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
	
//.............................................................Function Definition of Display...................................................
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

//...........................................................Function Definition of Display function based on priority..........................................
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

//......................................................................Function Definition of Delete entire list function................................
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

//......................................................................Function Defintion of Delete at beginning............................................
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

//......................................................................Function defintion of Delete based on priority function..................................
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
	temp=head;
	while(temp!=NULL)
	{
		if(temp->prior == priority)
		{
			p=temp;
			if(temp->prev!=NULL)
				temp->prev->next=temp->next;//last node
			else
				head=temp->next;
			if(temp->next!=NULL)//middle nodes
			{
				//temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				
			}
			free(p);
		}
		temp=temp->next;
	}
}*/
 
//........................................................Function defintion of Delete function  based on data and priority...................................
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
		printf("%d %d\n",iptr[i],dptr[i]);
		ptr->data=iptr[i];
		ptr->prior=dptr[i];
		//insert(iptr[i],dptr[i]);
//	}
		if(head==NULL)//when list is empty
		{
			ptr->prev=NULL;
			ptr->next=NULL;
			head=ptr;
		//	continue;
		
		}
		if(head->prior > dptr[i])//when given priority is less then the existing priority ....elements inserted at starting
		{
			ptr->prev=head->prev;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
		//	continue;
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
				//continue;
				break;
			}
			prv=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			ptr->next=NULL;//highest priority elements are inserted at last
			ptr->prev=prv;
			prv->next=ptr;
		}
	}
}*/
	
void create_list(int count)		
{
	struct node *ptr,*temp,*pr;
	int i,num,priority;
	for(i=0;i<count;i++)
	{
		printf("%d",i);
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
//		insert(num,priority);
 //}
		ptr->data=num;
		ptr->prior=priority;
		if(head==NULL)//list is empty
		{
			ptr->prev=NULL;
			ptr->next=NULL;
			head=ptr;
		}
		if(head->prior > priority)
		{
			ptr->prev=NULL;
			ptr->next=head;
			head->prev=ptr;
			head=ptr;
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
				break;
			}
			pr=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
		ptr->next=NULL;
		ptr->prev=pr;
		pr->next=ptr;
		}		
	}
}

void selection_sort_data()
{
	struct node *p,*q;
	int temp;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->prior==q->prior)
			{
				if(p->data > q->data)
				{
					temp=p->data;
					p->data=q->data;
					q->data=temp;
				}
			}
			else
				continue;
		}
	}
}


void selection_sort_data1(int priority)
{
        struct node *p,*q;
        int temp;
        for(p=head;p->next!=NULL;p=p->next)
        {
                for(q=p->next;q!=NULL;q=q->next)
                {
                        if((p->prior==priority)&&(q->prior==priority))
                        {
                                if(p->data > q->data)
                                {
                                        temp=p->data;
                                        p->data=q->data;
                                        q->data=temp;
                                }
                        }
                        else
                                continue;
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
			if(p->prior==q->prior)
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
					}
					temp=p;
					p=q;
					q=temp;
				}
			}
		}
	}
}


void selection_sort_address_priority(int priority)
{
	struct node *p,*q,*temp;
	for(p=head;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if((p->prior==priority)&&(q->prior==priority))
			{
				if((p->data)>(q->data))
				{
					if(p->next!=q)//non adjacent nodes
					{
						temp=p->prev;
						p->prev=q->prev;
						q->prev=temp;

						temp=p->next;
						p->next=q->next;
						q->next=temp;

						p->prev->next=p;
						q->next->prev=q;
						if(p!=head)
							q->prev->next=q;
						else
							head=q;
						if(p->next!=NULL)
							p->next->prev=p;
					}
					else//adjacent nodes
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
					temp=p;
					p=q;
					q=temp;
				}
			}
		}
	}
}
