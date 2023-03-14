#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
void remove_spaces(char *ptr);
void rotate_elements(int* arr,int n);
main()
{
	char src[100];
	int arr[MAX];
	int opt,i,n;
	while(1)
	{
		printf("Menu\n0.exit\n1.Remove spaces\n2.Rotate elements in array\n");
		printf("enter the option");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			
			case 1:
					printf("enter the string:");
					__fpurge(stdin);
					scanf("%[^\n]s",src);
					remove_spaces(src);
					break;
				
				
			case 2: for(i=0;i<MAX;i++)
				{
					printf("enter the inputs:");
					__fpurge(stdin);
					scanf("%d",&arr[i]);
				}
				printf("enter the no.of times to be rotated:");
				__fpurge(stdin);
				scanf("%d",&n);
				rotate_elements(arr,n);
				break;
				
			default:printf("Invalid option:");
		}
			printf("\n......................................\n");
	
	}

	
}

void remove_spaces(char* ptr)
{
	int i,j,k;
	for(i=0;ptr[i]!='\0';i++)
	{
		if(ptr[i]==' ')
		{
			for(j=i+1;ptr[j]==' ';j++)
			{
				for(k=j;ptr[k]!='\0';k++)
				ptr[k]=ptr[k+1];
			}
		}
	}
	ptr[i]='\0';
	printf("%s",ptr);
}


void rotate_elements(int* arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		temp=arr[0];
		for(j=0;j<MAX-1;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[j]=temp;
	}
	for(i=0;i<MAX;i++)
	printf("%d",arr[i]);
}
