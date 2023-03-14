//wap to print command line arguments

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void free(void* ptr);
void binary_values(int ptr);
void ascending_order(int* ptr,int n);
void descending_order(int* ptr,int n);
int palindrome(int ptr,int n);
main(int argc,char*argv[])
{
	int i=0,j,stat,k=0,temp,sum=0;
	int* ptr;
	char opt;
		
	if(argc<2)
	{
		printf("enter valid number of inputs");
		exit(1);
	}

	if(argv[1][0]!='-')
	{
		printf("enter valid flag as '-'");
		exit(2);
	}

	if(!( (argv[1][1]=='a') || (argv[1][1]=='b') || (argv[1][1]=='c') || (argv[1][1]=='d') ))
	{
		printf("enter valid option");
		exit(3);
	}
	ptr=(int*)malloc((argc-2)*sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to allocate memory in heap:");
			exit(4);
	}
		for(i=2;i<argc;i++)
		{
				//int sum=0;
				for(j=0;argv[i][j]!='\0';j++)
				{
					if(argv[i][j]>='0'&&argv[i][j]<='9')
					{
						temp=argv[i][j]-48;
						sum=sum*10+temp;
					}
					else
					{
						printf("enter the valid input");
						free(ptr);
						exit(4);
					}
				}
				ptr[k]=sum;
				k++;
				sum=0;
		}
		ptr[k]='\0';	
		printf("Menu\n a.binary_value\n b.ascending_order\n c.descending_order\n d.palindrome\n");
		switch(argv[1][1])
		{
			case 'a':printf("Binary output\n");
				for(i=0;i<(argc-2);i++)
				{
					binary_values(ptr[i]);
				}
				
					break;
					
			case 'b':printf("ASCENDING ORDER\n");
				ascending_order(ptr,argc-2);
				break;
			
			case 'c':printf("DESCENDING ORDER\n");
				descending_order(ptr,argc-2);
				break;
				
			case 'd':{
					int i,stat;
					for(i=0;i<(argc-2);i++)
					{
						stat=palindrome(ptr[i],argc);
						if(stat==ptr[i])
						{
							printf("palindrome %d\n",ptr[i]);
						}
						else
							printf("not a palindrome:");
					}
					break;
				}
				
			default:printf("enter the valid input:");
		}
}
		
		
void binary_values(int ptr)
{
	int j;
	printf("%d-",ptr);
	for(j=31;j>=0;j--)
	{
		if(((0x1<<j)&(ptr))==0)
			printf("0");
		else 
			printf("1");
	}
	printf("\n");
}


void ascending_order(int* ptr,int n)
{
	int j,temp,i;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]>ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
		printf("%d\t",ptr[i]);
	}
		
	//for(i=0;i<n;i++)
		//printf("%d\t",ptr);
}



void descending_order(int* ptr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]<ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
		printf("%d\t",ptr[i]);
	}
}

int palindrome(int ptr,int n)
{
	int i,j,temp,rem,sum=0;
	temp = ptr;
        for(i=0;temp!=0;i++)
        {
		rem=temp%10;
		temp=temp/10;
		sum = sum*10+rem;
 	}
	return sum;
}
							
