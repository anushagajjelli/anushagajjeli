/*#include<stdio.h>
void swap(int *ptr1,int *ptr2)
{
	int temp;
	temp=*ptr1;
	printf("%d\n",*ptr1);
	*ptr1=*ptr2;
	printf("%d\n",*ptr2);
	*ptr2=temp;
}
main()
{
	int a=10,b=20;
	swap(&a,&b);
	printf("a-%d\n b-%d\n",a,b);
}*/
/*main()
{
	unsigned int x=0x41424344;
	unsigned char *ptr=&x;
	printf("%x-%d-%c\n",*ptr,*ptr,*ptr);
}*/

/*main()
{
	unsigned int x=0x41424344;
	unsigned char *ptr=&x;
	*ptr=0xaabbccdd;
	printf("%x\n",x);
}*/
//biggest value in given range
#include<stdio.h>
void biggest_digit(int *ptr,int n);

void main(void)
{
	int n,i=0;
	int *ptr;
	ptr=(int *)malloc(5*sizeof(int));
	
	if(ptr==NULL)
	{
		printf("failed to access memory in heap");
		exit(1);
	}
	for(i=0;i<5;i++)
	{
		printf("enter the inputs\n");
		scanf("%d",&ptr[i]);
	}
	
	biggest_digit(ptr,5);
	free(ptr);
}
void biggest_digit(int *ptr,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		
		if (ptr[0]<ptr[i])
		{
			ptr[0]=ptr[i];
			//big=ptr[0];
		}
	}


	printf("%d",ptr[0]);
}
	
	
