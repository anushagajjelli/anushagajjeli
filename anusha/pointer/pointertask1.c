

#include<stdio.h>
#define NM 5
void read_integer(void *ptr,int n);
void display_integer(void *ptr,int n);
void biggest_value(void *ptr,int n);
void binary_conersion(void *ptr,int n);
void ascending(void *ptr,int n);
void second_biggest(void *ptr,int n);


void main()
{
	int opt,i,j,t,n,*ptr,*ptr1,num,sum=0,temp,k;
	ptr=(int *)malloc(NM*sizeof(int));
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
			case 1:printf("ENTER THE ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);
				read_integer(ptr,NM);
				break;

			case 2:printf("ENTER THE  ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);
				display_integer(ptr,NM);
				break;

			case 3:printf("ENTER THE ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&((int *)ptr)[i]);
				}
				biggest_value(ptr,NM);
				break;
			
			case 4:printf("ENTER THE  ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&((int *)ptr)[i]);
				}
				second_biggest(ptr,NM);
				break;

			case 5:
			{
				printf("ENTER THE  ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);
				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&((int *)ptr)[i]);
				
				}
				binary_conversion(ptr,NM);
				break;
			}
			case 6:
			{
				printf("ENTER THE  ELEMENTS:");
				scanf("%d",&n);
				//__fpurge(stdin);

				for(i=0;i<n;i++)
				{
					printf("enter the ptr[%d]:",i);
					scanf("%d",&((int *)ptr)[i]);
				}
				
				ascending(ptr,NM);
				break;
			}
			default:printf("invalid inputs\n");
		}
	}
	free(ptr);
}



void read_integer(void *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the input\n");
		scanf("%d",&((int *)ptr)[i]);
	}
	return i;
}

void display_integer(void *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the input\n");
		scanf("%d",&((int *)ptr)[i]);
		printf("%d's element---%p-%d\n",i+1,&(((int *)ptr)[i]),((int *)ptr)[i]);
		
	}
}

void biggest_value(void *ptr,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		
		if((((int *)ptr)[0])< ((int *)ptr)[i])
		{
			((int *)ptr)[0] = ((int *)ptr)[i];
			//big=ptr[0];
		}
	}


	printf(" biggest value-%d",((int *)ptr)[0]);
}




void second_biggest(void *ptr,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*((int *)ptr+j) < *((int *)ptr+i))
			{
				t = *((int *)ptr+i);
				*((int *)ptr+i) = *((int *)ptr+j);
				*((int *)ptr+j) = t;
			}
			//printf("%d\n",*(ptr+j));
		}
	}
	//printf("ascending order:");
	//for (i = 0; i<n; i++) 
        //printf("%d ", *(ptr+i)); 
	printf("second_biggest number:");

	printf("%d",((int *)ptr)[n-2]);
}



void binary_conversion(void *ptr,int n)
{
	int i,k=1,sum=0,temp,num;
	
	printf("DEC\tBINARY\n");
	for(i=0;i<n;i++)
	{
		num = ((int *)ptr)[i];
		sum=0;
		k=1;
		while(num>0)
		{
			
			temp=num%2;
			num=num/2;
			sum=sum+k*temp;
			k=k*10;
		}
		printf("%d\t%d\n",((int *)ptr)[i],sum);
	}
}



void ascending(void *ptr,int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*((int *)ptr+j) < *((int *)ptr+i))
			{
				t=*(((int *)ptr)+i);
				*((int *)ptr+i)=*((int *)ptr+j);
				*((int *)ptr+j)=t;
			}
			//printf("%d\n",*(ptr+j));
		}
	}
	printf("ascending order:");
	for (i = 0; i<n; i++) 
        printf("%d ", *(((int *)ptr)+i)); 
	printf("\ndesceding order is:");
	for(i=n;i>0;i--)
	printf("%d ",*(((int *)ptr)+(i-1)));
	printf("\nsmallest number : %d",((int *)ptr)[0]);
	printf("\nlargest number :%d",((int *)ptr)[n-1]);

	
	  
}






















