//wap to remove the conjunctive spaces in a given array...ex:I/P-moschip___semiconductor___technology..O/P:moschip_semiconductor_technology(____these are spaces)
//wap to rotate elements in given array by given no.of times...ex:I/P:{1,2,3,4,5}->n=2..O/P:{3,4,5,1,2}


#include<stdio.h>
#define SIZE 5
void remove_spaces(char* ptr);
void rotate_elements(int* arr,int k);
main()
{
	int src;
	int opt,i,k;
	while(1)
	{
		printf("Menu\n0.exit\n1.Remove conjuctive spaces\n2.Rotate elements\n");
		printf("select the option:");
		scanf("%d",&opt);
		switch(opt)
		{
		
			case 0:exit(0);
				break;
		
			case 1://printf("REMOVE SPACES\n");
				printf("enter the string:");
				scanf("%[^\n]s",src);
				remove_spaces(arr);
				break;

			case 2:printf("ROTATED ELEMENTS \n:");
				for(i=0;i<SIZE;i++)
				{
					printf("enter the inputs\n");
					scanf("%d",&arr[i]);
				}
				printf("enter the no from where to be rotated\n");
				__fpurge(stdin);
				scanf("%d",&k);
				rotate_elements(arr,k);
				break;
			
			default:printf("INVALID OPTION:");
		}
	}

}


void remove_spaces(int* arr)
{
	int i,j,l;
	l=strlen(src);
	for(i=0;i<l;i++)
	{
		if(arr[0]==' ')
		{
			for(i=0; i<(l-1) ;i++)
			{
				arr[i]=arr[i+1];
			}
			arr[i] = '\0';
			l--;
			i=-1;
			continue;
		}
		if(arr[i]==' '&&arr[i+1]==' ')
		{
			for(j=i+1;j<(l-1);j++)
			{
				arr[j]=arr[j+1];
			}
			arr[j]='\0';
			l--;
			i--;
		}
	}
	printf("%s",arr);

}
void rotate_elements(int* arr,int k)
{
	int i,j,temp;
	for(i=0;i<k;i++)
	{
		temp=arr[0];
		for(j=0;j<SIZE-1;j++)
		{
			arr[j]=arr[j+1];
			//printf("%d",arr[i]);
			arr[SIZE-1]=temp;
		}
		//n++;
			
	}
	for(i=0;i<SIZE;i++)
	printf("%d",arr[i]);
}
	
			

