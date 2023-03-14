#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
void display();
void add_atbegin(int num);
void add_atlast(int num);
void add_afteranode(int num,int val);
void add_beforeanode(int num,int val);
void delete_atbegin();
void delete_atlast();
void delete_entire();
void delete_particularnode(int num);
void create_alist(int *dptr,int num);
void main()
{
	int opt;
	int num;
	int val;
	int list;
	while(1)
	{
		printf("0.exit\n1.insertatbegin\n2.display\n3.deleteatbegin\n4.addatlast\n5.deleteatlast\n6.deletentire\n7.addafteranode\n8.addbeforeanode\n9.deleteparticularnode\n10.createalist\n");
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
			case 3:delete_atbegin();
			       break;
			case 4:printf("enter the number\n");
			       scanf("%d",&num);
			       add_atlast(num);
			       break;
			case 5:delete_atlast();
			       break;
			case 6:delete_entire();
			       break;
			case 7:printf("enter the number and val\n");
			       scanf("%d%d",&num,&val);
			       add_afteranode(num,val);
			       break;
			case 8:printf("enter the number and val\n");
			       scanf("%d%d",&num,&val);
			       add_beforeanode(num,val);
			       break;
			case 9:printf("enter the number\n");
			       scanf("%d",&num);
			       delete_particularnode(num);
			       break;
			case 10:{
					int i;
					int *ptr;
					printf("enter the no.of elements to create a list\n");
					scanf("%d",&list);
					ptr=(int *)malloc(list*sizeof(int));
					if(ptr==NULL)
					{
						printf("there is no memory in heap segment\n");
						exit(1);
					}
					for(i=0;i<list;i++)
					{
						printf("enter the element\n");
						scanf("%d",&ptr[i]);
					}
					create_alist(ptr,list);
					break;
				}

			default:printf("enter the valid option\n");
		}
	}
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
	if(head==NULL)//here head should not be NULL in circular list
	{
		head=ptr->link=ptr;//because when one node is there it will be the first and last node.
		return;
	}
	temp=head;
	while(temp->link!=head)//as we are doing add at begin 
	{
		temp=temp->link;
	}
	ptr->link=head;//the new node will be pointed as first node
	head=temp->link=ptr;
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
		temp=temp->link;
	}while(temp!=head);
}

void delete_atbegin()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("there is no memory\n");
		return;
	}
	if(head->link==NULL)
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
		ptr->link=head=ptr;
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
        temp->link=ptr;
        ptr->link=head;
}

void delete_atlast()
{
	struct node *prev,*next;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==head)
	{
		free(head);
		head=NULL;
		return;
	}
	prev=head;
	next=head->link;
	while(next->link!=head)
	{
		prev=next;
		next=next->link;
	}
	prev->link=head;
	free(next);
}
void delete_entire()
{
	struct node *temp,*cons;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	while(temp->link!=head)
	{
		cons=temp;
		temp=temp->link;
		free(cons);
	}
	free(temp);
	head=NULL;
}


void add_afteranode(int num,int val)
{
	struct node *temp,*ptr;
	ptr=(struct node *)malloc(1*sizeof(struct node));
	if(ptr==NULL)
	{
		printf("there is no memory in heap segment\n");
		return;
	}
	ptr->data=val;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	temp=head;
	if(head->data==num)
	{
		ptr->link=head->link;
		head->link=ptr;
	}
	temp=head->link;
	while(temp!=head)
	{
		if(temp->data==num)
		{
			ptr->link=temp->link;
			temp->link=ptr;
		        return;
		}
		temp=temp->link;
	}
	printf("element not found\n");
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
			printf("there is no memory in heap segment\n");
			exit(1);
		}
		ptr->data=val;
		ptr->link=head->link;
		head=ptr;
		head->link=ptr;
		return;
	}
	prev=head;
        cur=head->link;
	while(cur!=head)
	{
		if(cur->data==num)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("there is no memory in heap segment\n");
				exit(1);
			}
			ptr->data=val;
			ptr->link=cur;
			prev->link=ptr;
			return;
		}
		prev=cur;
		cur=cur->link;
	}
	printf("element not found\n");
}

void delete_particularnode(int num)
{
	struct node *temp;
	struct node *prev;
	struct node *cur;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->data==num)
	{
		if(head->link==head)
		{
			free(head);
			head=NULL;
			return;
		}
	}
	prev=head;
	cur=head->link;
	while(cur!=head)
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
	printf("element not found\n");
}

void create_alist(int *dptr,int num)
{
	int i;
	struct node *ptr;
	struct node *prev,*cur;
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
			head=ptr->link=ptr;
		
		}
		else
		{
			cur=head->link;
			while(cur->link!=head)
			{
				cur=cur->link;
			}
			ptr->link = cur->link;
			cur->link = ptr;
		}
	}
}

	

































