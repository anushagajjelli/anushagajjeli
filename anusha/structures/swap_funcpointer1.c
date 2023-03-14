//wap to perform function pointer

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
//..........................................Global variables.....................................
int i=0;
int j=0;
//........................................Function Declaration...................................
struct employee* allocation(struct employee *ptr,int n);
void read(struct employee *ptr,int n);
void swapping(struct employee *ptr,int n);
void display(struct employee *ptr,int n);
void deallocation(struct employee *ptr,int n);
//..........................................Structure Datatypes...................................
struct dob//structure within the structure
{
	int date;
	int month;
	int year;
};

struct employee
{
	char name[32];
	float salary;
	struct dob dt;
};

struct employee_ops
{
	struct employee *(*memory_allocation)(struct employee*ptr,int n);
	void(*f_read)(struct employee *ptr,int n);
	void(*f_swap)(struct employee *ptr,int n);
	void(*f_display)(struct employee *ptr,int n);
	void(*memory_deallocation)(struct employee *ptr,int n);
};
//..........................................main function............................................
void main()
{
	//struct employee ops;
	//printf("size of ops-%ld\n",sizeof(ops));
	struct employee s;
	printf(" total size -%ld\n",sizeof(s));
	int opt,n;
	struct employee *ptr=NULL;
	struct employee_ops op;//to access the members 
	
//................................Function pointers.................................
	op.memory_allocation=allocation;
	op.f_read=read;//it access the read function definition from the entire struct employee with starting base address
	op.f_swap=swapping;//it access the swap function from the entire struct employee with starting base address
	op.f_display=display;//it access the display function from the entire struct employee with starting base address
	op.memory_deallocation=deallocation;
	

	while(1)
	{
		printf("Menu\n0.exit(0)\n1.Memory allocation\n2.Read\n3.Swap\n4.Display\n5.Memory Deallocation\n");
		printf("Select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
				break;
				
			case 1:printf("Enter the no.of employees\n");
				scanf("%d",&n);
		                       i++;
					if(i==1)
					{
						ptr=op.memory_allocation(ptr,n);
						//j++;
						if(ptr==NULL)
							printf("failed ti allocate memory\n");
						else
							printf("\n............................Memory is allocated...................\n");
					}
					else if(i>=2)
					{
						printf("\n..............................Memory is already allocated,kindly perform read operation...............................\n");
					}
					
				break;
			
			case 2:
				if(i>0)
				{
					op.f_read(ptr,n);
					j++;
					
				}
				else if(i==0)
					printf("\n.......................Allocate the memory before giving inputs................\n");
				break;
				
			case 3: if((i==0)||(j==0))
				{
					printf("\n...................Memory is not allocated\n............................");
				}
				else if(i>0)
				{
					printf("Perform swap operation\n");
					op.f_swap(ptr,n);
				}	printf("\n.........................swapping performed....................\n");
				break;
				
			case 4: printf("Perform display\n");
				if(j==0)
					printf("....................Memory is deallocated ,kindly allocate the memory..................\n");
				else 
				{
					if(j>0)
						op.f_display(ptr,n);
					
					else if(i==0)
						printf("\n.............................there is no Memory and no data to display.........................\n");
				}		
				break;
				
			case 5:if(i==0)
				{
					printf("Memory is not allocated...Please allocate the memory\n");
				}
				else
				{
					op.memory_deallocation(ptr,n);
					i--;
					j--;
				printf("\n.....................Memory is deallocated.................\n");
				}
				break;
			
			default:printf("Invalid option\n");
		}
		//printf("\n..............................................................\n");
	}


}

//.....................................Function definition of memory allocation.........................................
struct employee* allocation(struct employee* ptr,int n)
{
	struct employee *ptr_mem=(struct employee*)malloc(n*sizeof(struct employee));
	if(ptr_mem==NULL)
	{
		printf("failed to allocate memory in heap segment\n");
		exit(0);
	}
	return ptr_mem;
	
}


//.........................................Function definition of Read details of two employees...............................
void read(struct employee *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n.............................Enter the details of the employee-%d........................\n",i+1);
		printf("Enter the employee name:");
		scanf("%s",ptr[i].name);
		__fpurge(stdin);
	
		printf("Enter salary:");
		scanf("%f",&ptr[i].salary);
		__fpurge(stdin);
	
		printf("Enter date-month-year:");
		scanf("%2d-%2d-%4d",&ptr[i].dt.date,&ptr[i].dt.month,&ptr[i].dt.year);
		__fpurge(stdin);
	}
	printf("\n");
}

//............................................Function definition of swapping operation.............................................
void swapping(struct employee *ptr,int n)
{
	int i;
	for(i=0,n;i<n;i++,n--)
	{
		struct employee temp;
		strcpy(temp.name,ptr[i].name);
		strcpy(ptr[i].name,ptr[n-1].name);
		strcpy(ptr[n-1].name,temp.name);
	
		temp.salary=ptr[i].salary;
		ptr[i].salary=ptr[n-1].salary;
		ptr[n-1].salary=temp.salary;
	
		temp.dt=ptr[i].dt;
		ptr[i].dt=ptr[n-1].dt;
		ptr[n-1].dt=temp.dt;
	}
	//printf("\n....................................................\n");
}

//.............................................Function definition of display..........................................................
void display(struct employee *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("................................EMPLOYEE DETAILS-%d.......................\n",i+1);
		printf("%p-%s\n",ptr[i].name,ptr[i].name);
		printf("%p-%f\n",&ptr[i].salary,ptr[i].salary);
		printf("%p-%d-%d-%d\n",&ptr[i].dt,ptr[i].dt.date,ptr[i].dt.month,ptr[i].dt.year);
	}
}

//..........................................Function definition of Memory deallocation.................................................
void deallocation(struct employee *ptr,int n)
{
	free(ptr);
}

