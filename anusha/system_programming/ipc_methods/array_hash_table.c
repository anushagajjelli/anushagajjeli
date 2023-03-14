//Hash table implementation by using arrays
#include<stdio.h>
#define size 7
void init();
void insert(int value);
void print();

int arr[size];
void main()
{
	init();
	insert(299);
	insert(2);
	insert(1);
	insert(299);
	printf("\n Hash table\n");
	print();
}
void init()
{
	int i;
	for(i=0;i<size;i++)
		arr[i]=-1;
}
void insert(int value)
{
	int key=value%size;
	if(arr[key]==-1)
	{
		arr[key]=value;
		printf("%d inserted ar arr[%d]\n",value,key);
	}
	else
	{
		printf("Collision or element %d is already\n",arr[key]);
	}

}
void print()
{
	int i;
	for(i=0;i<size;i++)
		printf("arr[%d] = %d\n",i,arr[i]);
}



