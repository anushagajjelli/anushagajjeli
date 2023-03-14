//wap to print the alphabets in descending order

#include<stdio.h>
#include<string.h>
//int descending_alphabets(char* ptr);
main()
{
	int i,j;
	char temp;
	//char* ptr;
	char arr[100];
	printf("enter the string:");
	scanf("%s",arr);
	for(i=0;arr[i]!='\0';i++)
	{
		//if((arr[i]>='a'&& arr[i]<='z')||(arr[i]>='A'&& arr[i]<='Z'))
		//{
			//or(j=i+1;arr[j]!='\0';j++)
			//{
				if(arr[i]<arr[i+1])
				{
					temp=arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
				}
			//}
		//}
	}
	//arr[i]='\0';
	//for(i=0;arr[i]!='\0';i++)
	printf("%s",arr);
}
