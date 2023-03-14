#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#define A 5
#define B 5
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
void adding_data(int *iptr,int num);
void display(struct node *header);
void merg_sorting();
int main()
{
	int prog,num,i,*ptr1,*ptr2;
	while(1)
	{
		printf(">>>>>>>>>>>>>>>>.Merg----Sort<<<<<<<<<<\n");
		printf("0.Exit the program\n1.Read the values\n2.Display data\n3.Merg sorting\n");
		scanf("%d",&prog);
		switch(prog)
		{
			case 0:
				printf("Exit te program\n");
				exit(0);

			case 1:
				printf("Merg sort\n");
				ptr1=(int *)malloc(A*sizeof(int));
				if(ptr1==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(1);
				}
				for(i=0;i<A;i++)
				{
					printf("First group of elements\n");
					scanf("%d",&ptr1[i]);
					__fpurge(stdin);
				}
				adding_data(ptr1,A);
				head1=head;
				head=NULL;
				ptr2=(int *)malloc(B*sizeof(int));
				if(ptr2==NULL)
				{
					printf("Failed to allocate the memory in heap segment\n");
					exit(1);
				}
				for(i=0;i<B;i++)
				{
					printf("Second group of elements\n");
					scanf("%d",&ptr2[i]);
					__fpurge(stdin);
				}
				adding_data(ptr2,B);
				head2=head;
				head=NULL;
				printf("First group of elements is\n");
				display(head1);
				printf("Second group of elements is:\n");
				display(head2);
				merg_sorting();
				display(head3);

				break;


		}
	}
}
void adding_data(int *iptr,int num)
{
	int i;
	struct node *ptr,*start=NULL,*prev;
        for(i=0;i<num;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		if(ptr==NULL)
		{
			printf("Failed to allocate the memory in heap segment\n");
			exit(0);
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
void merg_sorting()
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
		if(p->data<q->data)
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
















