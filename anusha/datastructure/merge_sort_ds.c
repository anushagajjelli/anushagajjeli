//.....................................HEADERFILES.................................
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
//......................................MACRO DEFINTIONS..............................
#define M 5
#define N 5
//.....................................STRUCTURE DEFINITION.............................
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
//......................................FUNCTION DECLARATIONS............................
void adding_elements(int *iptr,int num);
void display(struct node *header);
void merge_sort();
//.....................................MAIN FUNCTION...................................
void main()
{
	int opt,num,i,j,*ptr1,*ptr2;
	while(1)
	{
		printf("\n\n\tMenu\n\n\t0.exit\n\n\t1.Adding the elements\n\n\t2.Display\n\n\t3.Merge Sorting\n\n\t");
		printf("Enter the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:ptr1=(int *)malloc(M*sizeof(int));
				if(ptr1==NULL)
				{
					printf("Failed to allocate the memory\n");
					exit(1);
				}
				for(i=0;i<M;i++)
				{
					printf("First list of data\n");
					__fpurge(stdin);
					scanf("%d",&ptr1[i]);
				}
				adding_elements(ptr1,M);
				head1=head;
				head=NULL;
				ptr2=(int *)malloc(N*sizeof(int));
				if(ptr2==NULL)
				{
					printf("Failed to allocate the memory \n");
					exit(2);
				}
				for(i=0;i<M;i++)
				{
					printf("Second list of data\n");
					__fpurge(stdin);
					scanf("%d",&ptr2[i]);
				}
				adding_elements(ptr2,N);
				head2=head; 
				head=NULL;
				printf("First group of data\n");
				display(head1);
				printf("Second group of data\n");
				display(head2);
				break;
				
			case 2:
				printf("Total elements after merging\n");
				display(head3);
				break;
				
			case 3:
				merge_sort();
				//printf("Total elements after merging\n");
					//display(head3);
				break;
				
		}
		printf("\n..........................................................\n");
	}
}

void adding_elements(int *iptr,int num)
{
	struct node *ptr,*prev,*start=NULL;
	int i;
		for(i=0;i<num;i++)
		{
			ptr=(struct node*)malloc(1*sizeof(struct node));
			if(ptr==NULL)
			{
				printf("Failed to allocate the memory\n");
				exit(3);
			}
			ptr->data=iptr[i];
			ptr->link=NULL;
			if(start==NULL)
				start=ptr;
			else
				prev->link=ptr;
			prev=ptr;
		}
		head=start;
	
}


void display(struct node *header)
{
	struct node *temp;
	if(header==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=header;
	while(temp!=NULL)
	{
		printf("The data is : %d\n",temp->data);
		temp=temp->link;
	}
}
void merge_sort()
{
	struct node *prev,*start=NULL,*temp,*p,*q,*ptr;
	if((head1==NULL)&&(head2==NULL))
	{
		printf("List is empty\n");
		return;
	}
	for(p=head1,q=head2;(p!=NULL && q!=NULL);         )
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(0);
		}
		if(p->data==q->data)
		{
			ptr->data=p->data;
			ptr->link=NULL;
			if(start==NULL)
			start=ptr;
			else
				prev->link=ptr;
			prev=ptr;
			p=p->link;
			q=q->link;
		}
		else if(p->data<q->data)
		{
			ptr->data=p->data;
			ptr->link=NULL;
			if(start==NULL)
				start=ptr;
			else
				prev->link=ptr;
			prev=ptr;
			p=p->link;
		}
		else
		{
			ptr->data=q->data;
			ptr->link=NULL;
			if(start==NULL)
			start=ptr;
			else
				prev->link=ptr;
			prev=ptr;
			q=q->link;
		}
	}
	for(p;p!=NULL;p=p->link)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(0);
		}
		ptr->data=p->data;
		ptr->link=NULL;
		if(start==NULL)
			start=ptr;
		else
			prev->link=ptr;
		prev=ptr;
	}
	for(q;q!=NULL;q=q->link)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(0);
		}
		ptr->data=q->data;
		ptr->link=NULL;
		if(start==NULL)
			start=ptr;
		else
			prev->link=ptr;
		prev=ptr;
	}
	head3=start;

}












		
		
	

	
	
