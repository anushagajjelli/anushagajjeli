#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
int search(int num)
{
	struct node * temp;
	int k=0,s=0;
	if(head==NULL)
	{
		printf("list is empty\n");
		//return ;
	}
	temp=head;
	//printf("%d",temp);
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			//printf("position is at -%d\n",pos);
			s++;
			return s+k;
		}
		temp=temp->link;
		k++;
			
	}
	if(s==0)
		return 0;
	
	//return pos+k;
}
