//wap for stack and queue using switchcase


#include<stdio.h>
#include<stdlib.h>
int i=-1,j=-1,k=0;
void push(int *ptr,int num);
void pop(int *ptr,int num);
void display(int *ptr);
int search(int *ptr,int num);
void insert(int *ptr,int num);
void delete(int *ptr,int num);
void display1(int *ptr);
int search1(int *ptr,int num);
void main()
{
	int arr[5];
	int opt,num,i,j,pos,*ptr;
	char sub_opt;
	printf("\nMenu\n0.exit\n1.stack\n2.queue\n");
	printf("select the option\n");
	scanf("%d",&opt);
	while(1)
	{
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("\nPERFORM THE STACK OPERATION\na.push\nb.pop\nc.display\nd.search\n");
				__fpurge(stdin);
				printf("enter the sub_opt:");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':
						{
							printf("PERFORM THE PUSH OPERATION\n");
							printf("enter the value:");
							scanf("%d",&num);
							push(arr,num);
							break;
						}
				
					case 'b':printf("PERFORM THE POP OPERATION\n");
						pop(arr,num);
						break;

					case 'c':printf("PERFORM THE DISPLAY\n");
						display(arr);
						break;
		
					case 'd':
						{
						printf("PERFORM THE SEARCH OPERATION\n");

						printf("enter the input:");
						scanf("%d",&num);
						pos=search(arr,num);
						if(pos==-1)
						{
							printf("element not found\n");
							break;
						}
						printf("element found at %d\n",pos);
						break;
						}
				default:printf("invalid option\n");
			  }
			printf("...................................................\n");
			break;
		
			case 2:printf("\nPERFORM THE QUEUE OPERATION\na.insert\nb.delete\nc.display\nd.search\n");
				__fpurge(stdin);
				printf("enter the sub_opt:");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':{
							printf("PERFORM THE INSERT OPEARTION\n");
							printf("enter the value:");
							scanf("%d",&num);
							insert(arr,num);
							break;
							}
				
					case 'b':printf("PERFORM THE DELETE OPEARTION\n");
						delete(arr,num);
						break;

					case 'c':printf("PERFORM THE DISPLAY1\n");
						display1(arr);
						break;
		
					case 'd':{
						printf("PERFORM THE SEARCH1 OPEARTION\n");	

						printf("enter the input:");
						scanf("%d",&num);
						pos=search1(arr,num);
						if(pos==-1)
						{
							printf("element not found\n");
							break;
						}
						printf("element found at %d\n",pos);
						break;
					}
				default:printf("invalid option\n");
			}
			printf(".............................\n");
			break;
			default:printf("invalid options\n");
		}
	}
}

void push(int *ptr,int num)
{
	if(ptr==NULL)
	return;
	if(i==4)
	{
		printf("stack is full\n");
		return;
	}
	i++;
	ptr[i]=num;
}




void pop(int *ptr,int num)
{
	if(i==-1)
	{
		printf("stack is empty\n");
		return;
	}
	printf("the removed element is %d\n ",ptr[i]);
	i--;
}

void display(int * ptr)
{
	if(ptr==NULL)
	return;
	int j;
	if(i==-1)
	{
		printf("stack is empty\n");
		return;
	}
	for(j=0;j<=i;j++)
	{
		printf("%d\n",ptr[j]);
	}
}



int search(int *ptr,int num)
{
	if(ptr==NULL)
	return;
	int j;
	if(i==-1)
	{
		printf("stack is empty\n");
		return -1;
	}
	for(j=0;j<=i;j++)
	{
		if(ptr[j]==num)
		return j+1;
	}
	return -1;
}


void insert(int *ptr,int num)
{
	if(ptr==NULL)
		return;
	if(j==-1)
		j++;
	if(i==4)
	{
		printf("Queue is full\n");
		return;
	}
	i++;
	ptr[i]=num;
}




void delete(int *ptr,int num)
{
	
	 if(j==5)
	{
		printf("removed element is %d\n",ptr[j]);
		j++;
		k++;
	}
	else
	{
		printf("Queue is empty\n");
		return;
	}
}

void display1(int * ptr)
{
	if(ptr==NULL)
	return;
	if(j==-1)
	{
		printf("Queue is empty\n");
		return;
	}
	k=j;
	for( ;k<=i;k++)
	{
		printf("%d\n",ptr[k]);
	}
}


int search1(int *ptr,int num)
{
	if(ptr==NULL)
		return;
	if(j==-1)
	{
		printf("Queue is empty\n");
		return -1;
	}
	for(k=0;k<=i;k++)
	{
		if(ptr[k]==num)
			return k+1;
	}
	return -1;
}

	

					
