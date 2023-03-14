/*for 5 integer values-10,20,30,40,50; read and dispaly in pointers*/

#include<stdio.h>
int read_integer(int *ptr,int n);
void display_integer(int *ptr,int n);
void biggest_value(int *ptr,int n);
void binary_conersion(int *ptr,int n);
void ascending(int *ptr,int n);
void second_biggest(int *ptr,int n);


void main()
{
	int opt,i,j,t,n,*ptr,*ptr1,num,sum=0,temp,k;
	ptr=(int *)malloc(5*sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to access memory in heap\n");
		exit(1);
	}
	while(1)
	{
		printf("\nselect the options\n0.exit\n1.read the input\n2.display the inputs\n3.biggest value\n4.second biggest value\n5.decimal to binary\n6.ascending order\n");
		printf("Enter the Option:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);
				read_integer(ptr,n);
				break;

			case 2:printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);
				display_integer(ptr,n);
				break;

			case 3:printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&ptr[i]);
				}
				biggest_value(ptr,n);
				break;
			
			case 4:printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&ptr[i]);
				}
				second_biggest(ptr,n);
				break;

			case 5:
			{
				printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&ptr[i]);
				
				}
				binary_conversion(ptr,n);
				break;
			}
			case 6:
			{
				printf("ENTER THE NO.OF ELEMENTS:");
				scanf("%d",&n);
				__fpurge(stdin);

				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&ptr[i]);
				}
				
				ascending(ptr,n);
				break;
			}
			default:printf("invalid inputs\n");
		}
	}
	free(ptr);
}



int read_integer(int *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the input\n");
		scanf("%d",&ptr[i]);
	}
	return i;
}

void display_integer(int *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the input\n");
		scanf("%d",&ptr[i]);
		printf("%d's element---%p-%d\n",i+1,ptr+i,*(ptr+i));
		
	}
}

void biggest_value(int *ptr,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		
		if (ptr[0]<ptr[i])
		{
			ptr[0]=ptr[i];
			//big=ptr[0];
		}
	}


	printf(" biggest value-%d",ptr[0]);
}




void second_biggest(int *ptr,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(ptr+j) < *(ptr+i))
			{
				t=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=t;
			}
			//printf("%d\n",*(ptr+j));
		}
	}
	//printf("ascending order:");
	//for (i = 0; i<n; i++) 
        //printf("%d ", *(ptr+i)); 
	printf("second_biggest number:");

	printf("%d",ptr[n-2]);
}



void binary_conversion(int *ptr,int n)
{
	int i,k=1,sum=0,temp,num;
	
	printf("DEC\tBINARY\n");
	for(i=0;i<n;i++)
	{
		num=ptr[i];
		sum=0;
		k=1;
		while(num>0)
		{
			
			temp=num%2;
			num=num/2;
			sum=sum+k*temp;
			k=k*10;
		}
		printf("%d\t%d\n",ptr[i],sum);
	}
}



void ascending(int *ptr,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(ptr+j) < *(ptr+i))
			{
				t=*(ptr+i);
				*(ptr+i)=*(ptr+j);
				*(ptr+j)=t;
			}
			//printf("%d\n",*(ptr+j));
		}
	}
	printf("ascending order:");
	for (i = 0; i<n; i++) 
        printf("%d ", *(ptr+i)); 
	printf("\ndesceding order is:");
	for(i=n-1;i>0;i--)
	printf("%d ",*(ptr+(i)));
	printf("\nsmallest number : %d",ptr[0]);
	printf("\nlargest number :%d",ptr[n-1]);

	
	  
}






























































