#include<stdio_ext.h>
#include<stdlib.h>
//--------------------------------------------------------struct datatype----------------------------------------------------------------
struct node
{
	struct node *prev;
	int data;
	int pv;
	struct node *next;
};
//-----------------------------------------------------function declarations-----------------------------------------------------------
void insert(int num,int priority);
void display_priority(int priority);
void display();
void delete_priority_list(int priority);
void delete_priority_data(int num,int priority);
void delete_first_node();
void delete_list();
//---------------------------------------------------global variables--------------------------------------------------------
struct node *head=NULL;
int flag=0;
//---------------------------------------------------main()----------------------------------------------------------
void main()
{
	int opt,num,priority;
	char sub_opt;
	while(1)
	{
		printf("\nMENU:\n\t0.exit\n\t1.Insert\n\t2.Display\n\t3.Delete\n");
		printf("\nEnter option to be performed:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:if(flag==0)
				       delete_list();                                                //function call to delete entire list
			       exit(0);
			case 1:__fpurge(stdin);
			       printf("Enter data to be added:");
			       scanf("%d",&num);
			       __fpurge(stdin);
			       printf("Enter it's priority value:");
			       scanf("%d",&priority);
			       insert(num,priority);                                                //function call to insert data and it's priority values
			       break;
			case 2:__fpurge(stdin);
			       printf("\n\t\ta.Display data of particular priority value\n\t\tb.Display whole data along with priorities\n");
			       printf("\n\t\tEnter option to be performed:");
			       scanf("%c",&sub_opt);
			       switch(sub_opt)
			       {
				       case 'a':__fpurge(stdin);
						printf("\nEnter the priority value:");
						scanf("%d",&priority);
						display_priority(priority);                        //function call to display data of particular priority value
						break;
				       case 'b':display();                                         //function call to display data
						break;
				       default:printf("\nEnter valid option\n");
			       }
			       break;
			case 3:__fpurge(stdin);
			       printf("\n\t\ta.Delete data of particular priority\n\t\tb.Delete data and priority\n\t\tc.Delete first node\n\t\td.Delete entire list\n");
			       printf("\n\t\tEnter option to be performed:");
			       scanf("%c",&sub_opt);
			       switch(sub_opt)
			       {
				       case 'a':__fpurge(stdin);
						printf("\nEnter the priority value:");
						scanf("%d",&priority);
						delete_priority_list(priority);                   //function call to delete data of particular priority 
						break;
				       case 'b':__fpurge(stdin);
						printf("\nEnter the number:");
						scanf("%d",&num);
						__fpurge(stdin);
						printf("\nEnter the priority value:");
						scanf("%d",&priority);
						delete_priority_data(num,priority);
						break;
				       case 'c':delete_first_node();
						break;
				       case 'd':flag++;
						delete_list();                                    //function call to delete entire list
						break;
				       default:printf("\nEnter valid option\n");
			       }
			       break;
			default:printf("\nEnter valid option\n");
		}
	}
}
//-----------------------------------------------------------------function definitions-----------------------------------------------------------------------------
//--------------------------------------function definition to insert data and it's priority----------------------------------------------- 
void insert(int num,int priority)
{
	struct node *temp,*ptr=NULL;
	int count=0;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->pv=priority;
	if(head==NULL)                    //if list is empty
	{
		ptr->next=ptr->prev=head;
		head=ptr;
		return;
	}
	temp=head;
	while(temp!=NULL)                 //loop to check whether given priority value is less than all the priority values which already exits in list
	{
		if(priority>=temp->pv)
			count++;
		temp=temp->next;
	}
	if(count==0)                     //if the given priority value is less than all other existing priority values
	{
		temp=head;
		ptr->prev=NULL;
		temp->prev=ptr;
		ptr->next=temp;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)          //loop to check whether given priority value is equal to already existing priority values
	{
		if(temp->pv==priority)
			break;
		temp=temp->next;
	}
	if(temp->pv==priority)
	{
		while(temp->pv==priority) //loop to check whether other priority values are equal with the given priority value by tranversing
		{
			if(temp->next==NULL)
				break;
			temp=temp->next;
		}
		if((temp->next==NULL)&&(temp->pv==priority)) //if the node is the last node and it's priority value is equal to given priority value
		{
			ptr->next=temp->next;
			ptr->prev=temp;
			temp->next=ptr;
			return;
		}
		ptr->prev=temp->prev;                        //if the node is not the last node
		ptr->next=temp;
		temp->prev->next=ptr;
		temp->prev=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)         //loop to check whether given priority value is greater than  already existing priority values
	{
		if(temp->pv<priority)
			break;
		temp=temp->next;
	}
	if(temp->pv<priority)
	{
		while(temp->pv<priority) //loop to check whether other priority values are less than the given priority value by tranversing
		{
			if(temp->next==NULL)
				break;
			temp=temp->next;
		}
		if((temp->next==NULL)&&(temp->pv<priority)) //if the node is the last node and it's priority value is equal to given priority value
		{
			ptr->next=temp->next;
			ptr->prev=temp;
			temp->next=ptr;
			return;
		}
		ptr->prev=temp->prev;                         //if the node is not the last node
		ptr->next=temp;
		temp->prev->next=ptr;
		temp->prev=ptr;
		return;
	}
}
//----------------------------------------------------function definition to display particular priority values-------------------------------------------------------------
void display_priority(int priority)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->pv==priority)
			printf(">[%d-%d]",temp->data,temp->pv);
		temp=temp->next;
	}
}
//---------------------------------------------------function definition to display all the data along with their priority values------------------------------------------------
void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf(">[%d-%d]",temp->data,temp->pv);
		temp=temp->next;
	}
}
//-----------------------------------------------function definition to delete data of particular priority values--------------------------------------------------------
void delete_priority_list(int priority)
{
	struct node *p,*temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->pv==priority)
		{
			p=temp;
			if(temp->prev==NULL)                        //if node is first node
			{
				head=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=NULL;
			}
			else                                        //if node is not the first node
			{
				temp->prev->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=temp->prev;
			}
			free(p);
		}
		temp=temp->next;
	}
}
//-----------------------------------------------function definition to delete particular data of particular priority----------------------------------------------------
void delete_priority_data(int num,int priority)
{
	struct node *temp,*p;
	temp=head;
	while(temp!=NULL)
	{
		if((temp->data==num)&&(temp->pv==priority))
		{
			p=temp;
			if(temp->prev==NULL)                        //if node is first node
			{
				head=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=NULL;
			}
			else                                        //if node is not the first node
			{
				temp->prev->next=temp->next;
				if(temp->next!=NULL)
					temp->next->prev=temp->prev;
			}
			free(p);
		}
		temp=temp->next;
			}
}
//--------------------------------------------------------function definition to delete first node----------------------------------------------------------------
void delete_first_node()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	head=head->next;
	head->prev=NULL;
	free(temp);
}
//---------------------------------------------------------function definition to delete entire list---------------------------------------------------------------------------
void delete_list()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	printf("\nData is deleted\n");
}
void create_list()
{
	int i,n;
	int (*ptr)[2]=NULL;;
	printf("\nEnter number of nodes to be added:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ptr=(int (*)[])malloc((1*2)*sizeof(int));
		printf("\nEnter data of element
