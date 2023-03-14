#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
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

