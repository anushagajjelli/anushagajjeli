#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include"header.h"
//...................................struct datatype..............................................
struct node
{
	int data;
	struct node* link;
};
//..................................struct global variable.........................................
struct node* head=NULL;
//.......................................main function.............................................
void main()
{
	int num,pos,opt,k,val,c,i,num1,num2;
	int* ptr;
	char sub_opt;
	while(1)
	{
		printf("\nMenu\n\t0.exit\n\t1.Add at beginning\n\t2.Delete at beginning\n\t3.Display\n\t4.Count\n\t5.Search\n\t6.Delete the entire list\n\t7.Add node at last\n\t8.Delete node at last\n\t9.Add node after a node\n\t10.Delete the particular node in the list\n\t11.Add a node before a node\n\t12.Reverse the list\n\t13.Create the list\n\t14.Swapping\n\t15.Delete Duplicate elements in the list\t\n");
		printf("Enter the option to perform:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
				break;
				
			case 1:printf("Enter the number to be add:");
				scanf("%d",&num);
				add_at_beginning(num);
				break;
				
			case 2:delete_at_beginning();
				break;
				
			case 3://printf("Perform the Display function\n");
				display(num);
				break;
			
			case 4://printf("Count of the data\n");
				k=count(num);
				printf("count of elements in the list -%d",k);
				break;
				
			case 5:printf("Enter the element to be searched:");
				scanf("%d",&num);
				pos=search(num);
				if(pos==0)
				{
					printf("element is not found in the list\n");
				}
				 else
				{
					printf("element is  found at :%d position",pos);
				}
				break;
				
			case 6:delete_entire_list();
				break;
				
			case 7:printf("Enter the element:");
				scanf("%d",&num);
				add_node_at_last(num);
				break;
				
			case 8:delete_last_node();
				break;
			
			case 9:printf("Enter the num and val inputs:");
				scanf("%d %d",&num,&val);
				add_after_a_node(num,val);
				break;
				
			case 10:printf("enter the data to delete the particular node:");
				scanf("%d",&num);
				delete_particular_node(num);
				break;
			
			case 11: printf("Enter the num and val inputs:");
				scanf("%d %d",&num,&val);
				add_before_a_node(num,val);
				break;
				
			case 12:reverse_the_list();
				break;
				
			case 13:
				printf("Enter the count:");
				//__fpurge(stdin);
				scanf("%d",&c);
				ptr=(int *)malloc(c*sizeof(int));
				if(ptr==NULL)
				{
					printf("Failed to allocate the memory in heap\n");
					exit(1);
				}
				for(i=0;i<c;i++)
				{
					printf("Enter the input\n");
					//__fpurge(stdin);
					scanf("%d",&ptr[i]);
				}
				create_list(ptr,c);
				free(ptr);
				break;
			
			case 14:printf("\n\ta.Swap by data \n\tb.Swap by link\n\t");
				printf("Enter the option:");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a': printf("Enter the elements to be swapped:");
						scanf("%d %d",&num1,&num2);
						swap_by_data(num1,num2);
						break;
					
					case 'b':printf("Enter the elements to be swapped:");
						scanf("%d %d",&num1,&num2);
						swap_by_link(num1,num2);
						break;	
					
					default:printf("Entered the invalid sub option\n");
				}
				break;
			
			case 15:delete_duplicate_node();
				break;
			default:printf("Invalid option\n");
		}
		printf("\n....................................................\n");
	}
}
