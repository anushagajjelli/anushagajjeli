//wap to print the reverse of the string

#include<stdio.h>
#include<string.h>
void reverse(char* arr,int l);
void main()
{
	char arr[10];
	
	printf("enter the string:");
	scanf("%s",arr);
	reverse(arr,strlen(arr)-1);
}


void reverse(char* arr,int l)
{
		printf("%c",arr[l]);
		l--;
		if(l>=0)
		{
			reverse(arr,l);
			//printf("%c",arr[l]);
		}
	
}
