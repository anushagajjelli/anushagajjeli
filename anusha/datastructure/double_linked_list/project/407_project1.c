#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
struct node
{
	int data;
	int priority;
	struct node *prev;
	struct node *next;
};

struct node *head=NULL;
void insert(int num,int priority);
void display_priority(int priority_value);
void display();
void delte_entire_list();
void delete_priority(int priority_value);
void delete_data_priority(int num,int priority_value);
void main()
{
	int num,priority_value,opt;
	char sub_opt;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Insert\n\t2.Display\n\t3.Delete entire list\n\t4.Delete\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);

			case 1:printf("Enter the data :");
			       scanf("%d",&num);
			       __fpurge(stdin);
			       printf("Enter the priority:");
			       scanf("%d",&priority_value);
			       insert(num,priority_value);
			       break;

			case 2:printf("\nMenu\n\ta.Display based on priority\n\tb.Display complete data\n\t");
			       printf("Enter the sub_option:");
			       __fpurge(stdin);
			       scanf("%c",&sub_opt);
			       switch(sub_opt)
			       {
				       case 'a':printf("Enter the priority:");
						scanf("%d",&priority_value);
						display_priority(priority_value);
						break;

					case 'b':display();
						 break;
				}
			       break;
			  
			   case 3:delete_entire_list();
				  break;

			   case 4:printf("\nMenu\n\ta.Delete based on priority\n\tb.Delete node based on priority and data\n\tc.Delete at beginning\n\t");
                               printf("Enter the sub_option:");
                               __fpurge(stdin);
                               scanf("%c",&sub_opt);
                               switch(sub_opt)
                               {
                                       case 'a':printf("Enter the priority:");
						__fpurge(stdin);
                                                scanf("%d",&priority_value);
                                                delete_priority(priority_value);
                                                break;

				       case 'b':printf("Enter the data:");
						__fpurge(stdin);
						scanf("%d",&num);
						printf("Enter the priority:");
						__fpurge(stdin);
						scanf("%d",&priority_value);
						delete_data_priority(num,priority_value);
                                                 break;
                                }
                               break;



			default:printf("Invalid option");
		}
	}
}

void insert(int num,int priority_value)
{
	struct node *ptr=NULL,*temp;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=num;
	ptr->priority=priority_value;
	if(head==NULL)
	{
		ptr->prev=ptr->next=NULL;
		head=ptr;
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		if(temp->priority==priority_value)//if temp priority is equal to priority value
			break;
		temp=temp->next;
	}
	if(temp->priority==priority_value)
	{
		while(temp->priority==priority_value)//checking for t ptr->prev=temp->prev;
		{
			if(temp->next==NULL)//if temp is last node
				break;
			temp=temp->next;
		}

		if((temp->next==NULL)&&(temp->priority==priority_value))//if temp is last node and having the same priority value then perform this operation
		{
			ptr->next=temp->next;
			ptr->prev=temp;
			temp->next=ptr;
			return;
		}
	//	if(temp->next!=NULL)//if temp is not a last node then perform this operation
	//	{
			ptr->prev=temp->prev;
			ptr->next=temp;
			temp->prev->next=ptr;
			temp->prev=ptr;
			return;
	//	}
	}
	temp=head;
	while(temp->next!=NULL)
	{
		if(temp->priority < priority_value)
			break;
		temp=temp->next;
	}
	if(temp->priority < priority_value)
	{
		while(temp->priority < priority_value)
		{
			if(temp->next==NULL)
				break;
			temp=temp->next;
		}
		if((temp->next==NULL)&&(temp->priority<priority_value))
		{
			ptr->next=temp->next;
			ptr->prev=temp;
			temp->next=ptr;
			return;
		}
	//	if(temp->next!=NULL)
	//	{
                        ptr->prev=temp->prev;
                        ptr->next=temp;
                        temp->prev->next=ptr;
                        temp->prev=ptr;
                        return;
          //      }
	}
	temp=head;
        while(temp->next!=NULL)
        {
                if(temp->priority >  priority_value)
                        break;
                temp=temp->next;
        }
        if(temp->priority > priority_value)
        {
                while(temp->priority > priority_value)
                {
                        if(temp->next==NULL)
                                break;
                        temp=temp->next;
                }
                if((temp->next==NULL)&&(temp->priority > priority_value))
                {
                        ptr->next=temp->next;
                        ptr->prev=temp;
                        temp->next=ptr;
                        return;
                }
            //   if(temp->next!=NULL)
              //  {
                        ptr->prev=temp->prev;
                        ptr->next=temp;
                        temp->prev->next=ptr;
                        temp->prev=ptr;
                        return;
               // }

        }



}


void display_priority(int priority_value)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==priority_value)
			printf("%d-%d\n",temp->data,temp->priority);
		temp=temp->next;
	}
}


void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d-%d\n",temp->data,temp->priority);
		temp=temp->next;
	}
}

void delete_entire_list()
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
}

void delete_priority(int priority_value)
{
	struct node *temp,*q;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->priority==priority_value)
		{
			q=temp;
			if(temp->prev==NULL)//single node or first node
			{
				head=temp->next;//single node
				if(temp->next!=NULL)//first node with multiple nodes
					temp->next->prev=NULL;
			}
			else
			{
				temp->prev->next=temp->next;//last node
				if(temp->next!=NULL)//middle node
					temp->next->prev=temp->prev;
			}
			free(q);
		}
		temp=temp->next;
	}
}

void delete_data_priority(int num,int  priority_value)
{
        struct node *temp,*q;
        temp=head;
        while(temp!=NULL)
        {
                if((temp->priority==priority_value)&&(temp->data==num))
                {
                        q=temp;
                        if(temp->prev==NULL)//single node or first node
                        {
                                head=temp->next;//single node
                                if(temp->next!=NULL)//first node with multiple nodes
                                        temp->next->prev=NULL;
                        }
                        else
                        {
                                temp->prev->next=temp->next;//last node
                                if(temp->next!=NULL)//middle node
                                        temp->next->prev=temp->prev;
                        }
                        free(q);
                }
                temp=temp->next;
        }
}

