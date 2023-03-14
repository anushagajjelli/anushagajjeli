#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
void add_atbegin(int num);
void add_atlast(int num);
void add_afteranode(int num,int val);
void add_beforeanode(int num,int val);
void display();
void delete_atbegin();
void delete_atlast();
void delete_entire();
void delete_particularnode();
void create_alist(int *dptr,int num);
void main()
{
	int opt;
	int num;
	int val;
	while(1)
	{
		printf("0.exit\n1.addatbegin\n2.display\n3.addatlast\n4.addafteranode\n5.addbeforeanode\n6.delete_atbegin\n7.delete_atlast\n8.deleteentirelist\n9.deleteparticularnode\n10.createalist\n");
		printf("enter the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("enter the number\n");
			       scanf("%d",&num);
			       add_atbegin(num);
			       break;
			case 2:display();
			       break;
			case 3:printf("enter the number\n");
			       scanf("%d",&num);
			       add_atlast(num);
			       break;
			case 4:printf("enter two numbers to search and to add\n");
			       scanf("%d%d",&num,&val);
			       add_afteranode(num,val);
			       break;
			case 5:printf("enter the two numbers to search and to add\n");
			       scanf("%d%d",&num,&val);
			       add_beforeanode(num,val);
			       break;
			case 6:delete_atbegin();
			       break;
			case 7:delete_atlast();
			       break;
			case 8:delete_entire();
			       break;
			case 9:printf("enter the number to be deleted\n");
			       scanf("%d",&num);
			       delete_particularnode(num);
			       break;
			case 10:{
					int count;
					printf("enter the count,to create list \n");
					scanf("%d",&count);
					int *ptr;
					int i;
					ptr=(int *)malloc(count*sizeof(int));
					if(ptr==NULL)
					{
						printf("there is no memory in heap segment\n");
						exit(1);
					}
					printf("enter the elements\n");
					for(i=0;i<count;i++)
					{
						scanf("%d",&ptr[i]);
					}
					create_alist(ptr,count);
					break;
				}

					
					
			default:printf("enter the valid option\n");
		}
	}
}
void add_atlast(int num)
{
	struct node *ptr;
	struct node *temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("there is no memory in heap segment\n");
		exit(1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->prev=ptr;
		head=ptr->next=ptr;
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	ptr->next=temp->next;
	ptr->prev=temp;
	ptr->prev->next=ptr;
	head->prev=ptr;
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	do
	{
		printf("%d\t\n",temp->data);
		temp=temp->next;
	}while(temp!=head);
}

void add_atbegin(int num)
{
	struct node *ptr;
	struct node *temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("there is no memory in heap segment\n");
		exit(1);
	}
	ptr->data=num;
	if(head==NULL)
	{
		ptr->prev=ptr;
		head=ptr->next=ptr;
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	ptr->next=head;
	ptr->prev=temp;
	ptr->next->prev=ptr;
	head=temp->next=ptr;
}
void add_afteranode(int num,int val)
{
	struct node *ptr;
	struct node *temp;
	ptr=(struct node*)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("there is no memory in heap segment\n");
		exit(1);
	}
	ptr->data=val;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next=head)
		{
			ptr->next=ptr->prev=head;
			ptr->prev->next=ptr;
			head->prev=head;
			return;
		}
	}
	temp=head->next;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			if(temp->next == head)
				temp->next->prev = ptr;
			ptr->next=temp->next;
			ptr->prev=temp;
			temp->next = ptr;
		        return;
		}
		temp=temp->next;
	}
	printf("no element found\n");
	
	
}
void add_beforeanode(int num,int val)
{
	struct node *ptr;
        struct node *prev,*cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("there is no memory segment in heap segment\n");
			exit(1);
		}
		ptr->data=val;
                ptr->next=head;
		ptr->prev=head->prev;
		head=ptr;
		ptr->next->prev=ptr;
		ptr->prev->next=ptr;
		return;
	}
	prev=head;
	cur=head->next;
	while(cur!=head)
	{
		if(cur->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("there is no memory segment in heap segment\n");
				exit(1);
			}
			ptr->data=val;
			if(cur->next==head)
			{

			       ptr->next=cur;
		               ptr->prev=prev;
			       cur->prev=prev->next=ptr;
			       return;
			}
			ptr->next=prev->next;
			ptr->next=cur->prev;
			ptr->next=cur->prev=ptr;
			return;
		}
		prev=cur;
		cur=cur->next;
	}
	printf("element not found\n");
}

void delete_atbegin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=head->next;
	head->prev=temp;
	free(head);
	head=temp->next;
}

void delete_atlast()
{
	struct node *prev;
	struct node *cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->next==head)
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	cur=head->next;
	while(cur->next!=head)
	{
		prev=cur;
		cur=cur->next;
	}
	prev->next=head;
	head->prev=prev;
	free(cur);
}
void delete_entire()
{
	struct node *temp;
	struct node *cons;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp->next!=head)
	{
		cons=temp;
		temp=temp->next;
		free(cons);
	
	}
	head=NULL;
}

void delete_particularnode(int num)
{
	struct node *cur,*t;
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->next==head)
		{
			free(head);
			head=NULL;
			return;
		}
		cur=head;
		head=head->next;
		head->prev=head->next=head;
		free(cur);
		return;
	}
	temp=head->next;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			temp->next->prev=temp->prev;
			if(temp->next==head)
			{
				temp->prev->next=head;
				head->prev=temp;
			}
			else
				temp->prev->next=temp->next;
			free(temp);
			return;

		}
		temp=temp->next;
	}
	printf("element not found\n");
}


void create_alist(int *dptr,int num)
{
	int i;
	struct node *ptr,*cur;
	for(i=0;i<num;i++)
	{
		ptr=(struct node*)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("there is no memory in heap segment\n");
			exit(1);
		}
		ptr->data=dptr[i];
		if(head==NULL)
		{
			head=ptr->next=ptr->prev=ptr;
		}
		else
		{
			ptr->prev=head->prev;
			ptr->next=head;
			ptr->prev->next=ptr;
			head->prev=ptr;
		}
	}
}






































