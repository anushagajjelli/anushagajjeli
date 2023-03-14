/*for 5 integer values-10,20,30,40,50; read and dispaly in pointers*/

#include<stdio.h>
int read_integer(int *ptr,int n);
void display_integer(int *ptr,int n);


int read_integer(int *ptr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("enter the input\n");
		scanf("%d",&ptr[i]);
	}
	return i;
}

/*void display_integer(int *ptr,int n)
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d's element---%p-%d\n",i+1,&ptr[i],ptr[i]);
		printf("%p-%d\n",&i[ptr],i[ptr]);
		printf("%p-%d\n",i+ptr,*(i+ptr));
		printf("%p-%d\n",&i[ptr],i[ptr]);
	}
}*/



int biggest_digit(int num)
{
	int big=0,temp;
	do{
		temp=num%10;
		num=num/10;
		if(temp>big)
			big=temp;
		return 0;
	}while(num>0);
	printf("%d",big);
}	
	
	








































































main()
{
	int *ptr;
	int i,n,num;
	ptr=(int *)malloc(5*sizeof(int));
	if(ptr==NULL)
	{
		printf("failed to access memory in heap\n");
		exit(1);
	}
	n=read_integer(ptr,5);
	//display_integer(ptr,num);
	num=biggest_digit(num);
	
	free(ptr);
}
