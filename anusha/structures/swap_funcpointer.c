//wap to perform function pointer

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
//..........................................Global variables.....................................
int i=0;
int j=0;
//........................................Function Declaration...................................
struct employee* allocation();
void read(struct employee *ptr);
void swapping(struct employee *e1,struct employee* e2);
void display(struct employee *ptr);
void deallocation(struct employee *ptr);
//..........................................Structure Datatypes...................................
struct dob
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
	struct employee *(*memory_allocation)();
	void(*f_read)(struct employee*);
	void(*f_swap)(struct employee*,struct employee*);
	void(*f_display)(struct employee*);
	void(*memory_deallocation)(struct employee*);
};
//..........................................main function............................................
void main()
{
	struct employee ops;//to check the size
	printf("%d",sizeof(ops));

	int opt;
	struct employee *e1,*e2;
	//printf("%d",sizeof(ops));
	struct employee_ops op;
	op.memory_allocation=allocation;
	op.f_read=read;
	op.f_swap=swapping;
	op.f_display=display;
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
				
			case 1:
					i++;
					if(i==1)
					{
						e1=op.memory_allocation();
						e2=op.memory_allocation();
						printf("\n............................Memory is allocated...................\n");
					}
					else
					{
						printf("\n...........................Memory is already allocated..........................\n");
						i--;
					}
					
				break;
			
			case 2://printf("...............Enter the details of the employee................\n");
				j++;
				if(i==j)
				{
					op.f_read(e1);
					op.f_read(e2);
				}
				else
					printf("\n.......................Allocate the memory before giving inputs................\n");
				break;
				
			case 3: printf("Perform swap operation\n");
				op.f_swap(e1,e2);
				printf("\n.........................swapping performed....................\n");
				break;
				
			case 4: printf("Perform display\n");
				if((i==1)&&(j==1))
				{
					op.f_display(e1);
					op.f_display(e2);
				}
				else
					printf("\n.................Memory is not allocated and no inputs.....................\n");
				break;
				
			case 5:if(i==1)
				{
					op.memory_deallocation(e1);
					op.memory_deallocation(e2);
					i--;
				}
				else 
					printf("Memory is not allocated...Please allocate the memory\n");
				break;
			
			default:printf("Invalid option\n");
		}
		printf("\n..............................................................\n");
	}


}

//.....................................Function definition of memory allocation.........................................
struct employee* allocation()
{
	struct employee *ptr=(struct employee*)malloc(1*sizeof(struct employee));
	if(ptr==NULL)
	{
		printf("failed to allocate memory in heap segment\n");
		exit(0);
	}
	return ptr;
	
}


//.........................................Function definition of Read details of two employees...............................
void read(struct employee *ptr)
{
	printf("\n...................................Enter the details of the employee...................................\n");
	printf("Enter the employee name:");
	scanf("%s",ptr->name);
	__fpurge(stdin);
	
	printf("Enter salary:");
	scanf("%f",&ptr->salary);
	__fpurge(stdin);
	
	printf("Enter date-month-year:");
	scanf("%2d-%2d-%4d",&ptr->dt.date,&ptr->dt.month,&ptr->dt.year);
	__fpurge(stdin);
	printf("\n");
}

//............................................Function definition of swapping operation.............................................
void swapping(struct employee *e1,struct employee* e2)
{
	struct employee temp;
	strcpy(temp.name,e1->name);
	strcpy(e1->name,e2->name);
	strcpy(e2->name,temp.name);
	
	temp.salary=e1->salary;
	e1->salary=e2->salary;
	e2->salary=temp.salary;
	
	temp.dt=e1->dt;
	e1->dt=e2->dt;
	e2->dt=temp.dt;
}

//.............................................Function definition of display..........................................................
void display(struct employee *ptr)
{
	printf("................................EMPLOYEE DETAILS.......................\n");
	printf("%p-%s\n",ptr->name,ptr->name);
	printf("%p-%f\n",&ptr->salary,ptr->salary);
	printf("%p-%d-%d-%d\n",&ptr->dt,ptr->dt.date,ptr->dt.month,ptr->dt.year);
}


//..........................................Function definition of Memory deallocation.................................................
void deallocation(struct employee *ptr)
{
	free(ptr);
}

	
