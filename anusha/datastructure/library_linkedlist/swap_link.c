#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
extern struct node *head;
void swap_by_link(int num1,int num2)
{
	struct node *p,*q,*r,*s,*temp;
	int pos1=0,pos2=0;
	if(num1==num2)//if both numbers are equal then no need to swap
		return;
	if(head==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=q=head;
	while(p!=NULL)
	{
		pos1++;
		if(p->data==num1)
			break;
		r=p;              //p-points current node and r-points the previous node of p
		p=p->link;
	}
	while(q!=NULL)
	{
		pos2++;
		if(q->data==num2)	
			break;
		s=q;             //q-points the current node and s-points the previous node of q
		q=q->link;
	}
	if((p==NULL)||(q==NULL))
	{
		printf("Element not found\n");
		return;
	}
	if(pos1>pos2)//if p position is greater than q then swap their positions
	{
		temp=p;
		p=q;
		q=temp;
		temp=r;
		r=s;
		s=temp;
	}
	if(p->link!=q)//for non-adjacent nodes
	{
		temp=p->link;
		p->link=q->link;
		q->link=temp;
		if(p!=head)// if p is not the first node
			r->link=q;
		else         //if p is first node then else part executes
			head=q;
		s->link=p;
		return;
	}
	else   
	{                           //for adjacent nodes of p and q then no need of s 
		p->link=q->link;
		q->link=p;
		if(p!=head)   //if p is not the first node
			r->link=q;
		else		//if p is first node
			head=q;
		return;
	}
}

