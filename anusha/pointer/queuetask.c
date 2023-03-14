//queue program:


#include<stdio.h>
#include<stdlib.h>
int i=-1,j=-1;
void insert(int *ptr,int n);
void delete();
void display(int *ptr);
int search(int *ptr,int num);
void main()
{
	int arr[5];
	int opt,num,i,j,k,pos,*ptr;
	while(1)
	{
	
		printf("\nMenu\n0.exit\n1.insert operation\n2.delete operation\n3.display\n4.search\n");
		printf("select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:{
					printf("PERFORM THE INSERT OPEARTION\n");
					printf("enter the value\n");
					scanf("%d",&num);
					insert(arr,num);
					break;
				}
			
			case 2:printf("PERFORM THE DELETE OPEARTION\n");
				delete();
				break;

			case 3:	printf("PERFORM THE DISPLAY\n");
				display(arr);
				break;
	
			case 4:{
					printf("PERFORM THE SEARCH OPEARTION\n");	

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
	}
}


void insert(int *ptr,int num)
{
	if(ptr==NULL)
	return;
	
	if(i==4)
	{
		printf("stack is full\n");
		return;
	}
	i++;
	j++;
	ptr[i]=num;
	//i++;
}




void delete()
{
	//int *ptr;
	//if(ptr==NULL)
	//return;
	if(j==-1)
	{
		printf("stack is empty\n");
		return;
	}
	j--;
}

void display(int * ptr)
{
	if(ptr==NULL)
	return;
	int k;
	if(j==-1)
	{
		printf("stack is empty\n");
		return;
	}
	for(k=0;k<=j;k++)
	{
		printf("%d\n",ptr[k]);
	}
}



int search(int *ptr,int num)
{
	if(ptr==NULL)
	return;
	int k;
	if(j==-1)
	{
		printf("stack is empty\n");
		return -1;
	}
	for(k=0;k<=i;k++)
	{
		if(ptr[k]==num)
		return k+1;
	}
	return -1;
}

	
