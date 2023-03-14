//Separate chaining implementation by using linked list
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{
	int data;
	struct node* link;
};
struct node *hash[size];

void init()
{
	int i;
	for(i=0;i<size;i++)
		hash[i]=NULL;
}
void insert(int value)
{
	struct node *new_node=(struct node*)malloc(1*sizeof(struct node));
	if(new_node==NULL)
	{
		printf("Memoey allocation is faild\n");
		exit(2);
	}
	new_node->data=value;
	new_node->link=NULL;
	int key=((value+25)%size)-1;
	if(hash[key]==NULL)
		hash[key]=new_node;
	else
	{
		struct node *temp=hash[key];
		while(temp->link)
		{
			temp=temp->link;
		}
		temp->link=new_node;
	}
}
void print()
{
	int i;
	for(i=0;i<size;i++)
	{
		struct node *temp=hash[i];
		printf("hash[%d]-->",i);
		while(temp)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
		printf("NULL-->\n");
	}
}
void main()
{
	init();
	insert(3);
	insert(2);
	insert(9);
	insert(6);
	insert(11);
	insert(13);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(7);
	insert(12);
	print();
}


