//wap to implement the stack ...use push and pop operations

#include<stdio.h>
#include<stdlib.h>
int i=-1;
void push(int *ptr,int num);
void pop(int *ptr,int num);
void display(int *ptr);
int search(int *ptr,int num);
void main()
{
	int arr[5];
	int opt,num,i,j,pos,*ptr;
	while(1)
	{
	
		printf("\nMenu\n0.exit\n1.push operation\n2.pop operation\n3.display\n4.search\n");
		printf("select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:{
					printf("PERFORM THE PUSH OPERATION\n");
					printf("enter the value\n");
					scanf("%d",&num);
					push(arr,num);
					break;
				}
			
			case 2:printf("PERFORM THE POP OPERATION\n");
				pop(arr,num);
				break;

			case 3:printf("PERFORM THE DISPLAY\n");
				display(arr);
				break;
	
			case 4:{
					printf("PERFORM THE SEARCH OPERATION\n");

					printf("enter the input\n");
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
	//int *ptr;
	//if(ptr==NULL)
	//return;
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

	
