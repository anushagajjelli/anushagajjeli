//wap to add the elements in the given index of the array ex: i/p:12345 index=2 o/p:127345

#include<stdio_ext.h>
#include<stdlib.h>
void main()
{
	int n,i,pos,temp,val,saru;
	printf("Enter the size:");
	scanf("%d",&n);
	saru=n;
	int *ptr;
	ptr=(int *)malloc(n*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory :");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter the input:");
		__fpurge(stdin);
		scanf("%d",&ptr[i]);
	}
	printf("Enter the position:");
	__fpurge(stdin);
	scanf("%d",&pos);
	ptr=(int*)realloc(ptr,(n+1)*sizeof(int));
	if(ptr==NULL)
	{
		printf("Failed to allocate the memory :");
		exit(1);
	}
	for(i=pos+1;i<=n;n--)
	{
		temp=ptr[n-1];
		ptr[n-1]=ptr[n];
		ptr[n]=temp;
		
	}
	printf("Enter the value:");
	scanf("%d",&val);
	ptr[pos]=val;
	for(i=0;i<=saru;i++)
		printf("%d\t",ptr[i]);
	
		


}
