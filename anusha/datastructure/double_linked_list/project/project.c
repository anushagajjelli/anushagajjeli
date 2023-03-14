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
void delete_priority(int priority);
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
                        case 0://if(flag==0)
                                 //       delete_entire_list();   //function call delete entire list
                                exit(0);

                        case 1:printf("Enter the data:");
                                scanf("%d",&num);
                                 printf("Enter the priority:");
                                __fpurge(stdin);
                                scanf("%d",&priority);
                                insert(num,priority);//function call of insert
                                break;
			case 2:display();
			       break;

			case 3:printf("E
		}
		printf("\n...................................................\n");
	}
}


void insert(int num,int priority)
{
	struct node *ptr,*temp,*p;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory in heap\n");
		exit(1);
	}
	ptr->data=num;
	ptr->prior=priority;
	if(head==NULL)
	{
		ptr->prev=NULL;
		ptr->next=NULL;
		head=ptr;
		return;
	}
	if(head->prior > priority)
	{
		ptr->next=head;
		ptr->prev=head->prev;
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
		p=temp;
		temp=temp->next;
	}
	ptr->next=NULL;
	p->next=ptr;
	ptr->prev=p;
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
		printf("Data-%d  Priority-%d\n",temp->data,temp->prior);
		temp=temp->next;
	}
}

