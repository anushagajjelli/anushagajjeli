//queue program:


#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int f=-1,r=-1,k=0;
void insert(int *ptr);
void delete(int *ptr);
void display(int *ptr);
void ascending(int *ptr);
void main()
{
	int arr[MAX];
	int i;
	int opt,num,pos;
	while(1)
	{
	
		printf("\nMenu\n0.exit\n1.insert operation\n2.delete operation\n3.display\n4.ascending\n");
		printf("select the option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:{
					printf("PERFORM THE INSERT OPEARTION\n");
					//printf("enter the value:");
					//scanf("%d",&num);
					insert(arr);
					break;
				}
			
			case 2:printf("PERFORM THE DELETE OPEARTION\n");
				delete(arr);
				break;

			case 3:	printf("PERFORM THE DISPLAY\n");
				display(arr);
				break;
			
			case 4:{
					ascending(arr);
					break;
				}
			default:printf("invalid option\n");
		}
		printf(".............................\n");

	}
}


void insert(int *ptr)
{
	int i,num;
	if(f==-1)
	{
		//printf("queue is empty\n");
		f++;
		r++;
		printf("enter the number:");
		printf("f=%d\n",f);
		scanf("%d",&num);
		ptr[r]=num;
		printf("number entered\n");
	}
	else if((r==(MAX-1)&&(f==0))||(r==f-1))//r==size-1...index values are from 0 to 4
	{
		printf("Queue is full\n");
		return;
	}
	else if(r==(MAX-1))
	{
		r=-1;
		printf("enter the value:");
		scanf("%d",&num);
		r++;
		ptr[r]=num;
		printf("value %d is inserted in queue at pos %d\n",num,(r+1));
		
		return;
	}
	else
	{
		r++;
		printf("r=%d\n",r);
		printf("enter the input:");
		scanf("%d",&num);
		ptr[r]=num;
		printf("value %d is inserted in queue at pos %d\n",num,(r+1));
		printf("r is %d\n",r);
		
		
	}		
	
}




void delete(int *ptr)
{
	
	if((f==-1)&&(r==-1))
	{
		printf("Queue is empty\n");
		return;
	}
	else if(f==r)//also consider if (f>r) then f=-1
	{
		printf("Queue is empty\n");
		f=-1;
		r=-1;
		return;
	}
	else
	{	
		f++;
		printf("removed element is %d\n",ptr[f]);
	}
		
	
}





void display(int * ptr)
{
	int i;
	if((f==-1)&&(r==-1))
	{
		printf("Queue is empty");
		return;
	}
	else if(f<=r)
	{
		printf("r is %d\n",r);
		printf("f is %d\n",f);
		for(i=f;i<=r;i++)
			printf("%p-%d\n",&ptr[i],ptr[i]);		
	}
	else if(r<f)
	{
		for(i=f;i<(MAX);i++)
		{	
			printf("%p-%d\n",&ptr[i],ptr[i]);
		}
		for(i=0;i<=r;i++)
		{
			printf("%p-%d\n",&ptr[i],ptr[i]);
		}
	}
}


void ascending(int *ptr)
{
	int arr1[MAX];
	int arr2[MAX];
	int temp;
	int i,k,j;
	for(i=0;i<(MAX);i++)
		arr2[i]=ptr[i];
	if(f==-1)
	{
		printf("queue is empty");
		f++;
		return;
	}
	if(f<r)
	{
		for(i=f;i<=r;i++)
		{	
			for(j=i+1;j<=r;j++)
			{
				if(arr2[i]>arr2[j])
				{
					temp=arr2[i];
					arr2[i]=arr2[j];
					arr2[j]=temp;
				}
			}
		}

		for(i=f;i<=r;i++)
			printf("%d\n",arr2[i]);
	}
	
	else if(r<f)
	{
		for(i=f,k=0;i<MAX;i++,k++)
		{
			arr1[k]=arr2[i];
			
		}
		printf("r is %d\n",r);
		printf("f is %d\n",f);
		printf("k is %d\n",k);
		for(i=0;i<=r;i++,k++)
		{
			arr1[k]=arr2[i];
			
		}
		for(i=0;i<k;i++)
		{
			for(j=i+1;j<k;j++)
			{
				if(arr1[i]>arr1[j])
				{
					temp=arr1[i];
					arr1[i]=arr1[j];
					arr1[j]=temp;
				}
			}
			printf("%d\n",arr1[i]);
		}
	}

	else if(r==f)
		printf("only single element %d\n",arr2[r]);
}




	
