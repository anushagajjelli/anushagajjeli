
#include<stdio.h>
#include<string.h>
void descending_alphabets(char* arr);
main()
{
	int i,j;
	//char* ptr;
	char arr[100];
	printf("enter the string:");
	scanf("%s",arr);
	descending_alphabets(arr);
}


void descending_alphabets(char* arr)
{
	int i,j;
	char temp;
	//char arr[100];
	for(i=0;arr[i]!='\0';i++)
	{
		if(arr[i]>='0'&& arr[i]<='127')//ascii values
		{
			for(j=i+1;arr[j]!='\0';j++)
			{
				if(arr[i]<arr[j])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	}
	//arr[i]='\0';
	//for(i=0;arr[i]!='\0';i++)
	printf("%s",arr);
}
