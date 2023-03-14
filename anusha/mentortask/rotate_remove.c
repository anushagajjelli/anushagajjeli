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
	int i,j,l;
	l=strlen(ptr);
	printf("before removing spaces %d",l);
	for(i=0;i<l;i++)
	{
		if(ptr[0]==' ')
		{
			for(i=0;i<(l-1);i++)
			{
				ptr[i]=ptr[i+1];
			}
				ptr[i]='\0';
				l--;
				i=-1;
				continue;
		}
		if((ptr[i]==' ')&&(ptr[i+1]==' '))
		{
			for(j=i;j<(l-1);j++)
			{
				ptr[j]=ptr[j+1];
			}
			ptr[j]='\0';
			l--;
			i=-1;
		}
	}
	printf("after removing spaces %d",l);
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
		
		
