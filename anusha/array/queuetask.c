//queue program:


#include<stdio.h>
#include<stdlib.h>
int i=-1,j=-1,k=0;
void insert(int *ptr,int num);
void delete(int *ptr,int num);
void display(int *ptr);
int search(int *ptr,int num);
void main()
{
	int arr[5];
	int opt,num,pos;
	while(1)
	{
	
		printf("\nMenu\n0.exit\n1.insert operation\n2.delete operation\n3.display\n4.search\n");
		printf("select the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:{
					printf("PERFORM THE INSERT OPEARTION\n");
					printf("enter the value:");
					scanf("%d",&num);
					insert(arr,num);
					break;
				}
			
			case 2:printf("PERFORM THE DELETE OPEARTION\n");
				delete(arr,num);
				break;

			case 3:	printf("PERFORM THE DISPLAY\n");
				display(arr);
				break;
	
			case 4:{
					printf("PERFORM THE SEARCH OPEARTION\n");	

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
		printf(".............................\n");

	}
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
		printf("Queue is empty\n");
		return;
	}
		printf("removed element is %d\n",ptr[j]);
		j++;
		k++;
}

void display(int * ptr)
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


int search(int *ptr,int num)
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

	
