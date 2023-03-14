//problems on pointers

/*#include<stdio.h>
void display(int x[5],int n);
main()
{
	int x[5]={10,20,30,40,50};
	display(x,5);
}

void display(int x[5],int n)
{
	int i;
	printf("%d\n",sizeof(x));
	for(i=0;i<n;i++)
		printf("%d\n",x[i]);
}*/


main()
{
	 int *ptr1=0x5000;
	 int *ptr2=0x6000;
	printf("%d\n",(ptr2-ptr1));
}


/*main()
{
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int ret;
	ret=&ptr[2]-&ptr[0];
	printf("%d",ret);
}*/


/*main()
{
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int ret;
	ret=((void*)&ptr[2])-((void*)&ptr[0]);
	printf("%d",ret);
}*/
		

/*main()
{
	int x[5]={1,2,3,4,5};
	int *ptr=x;
	int ret;
	ret=((char*)&ptr[2])-((char*)&ptr[0]);
	printf("%d",ret);
}*/
		
