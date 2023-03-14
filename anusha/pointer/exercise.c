
/*#include<stdio.h>
int main(void)
{
	//int arr[5];
	int i,arr[5]={25,30,35,40,45},*p;
	//arr[5]={25,30,35,40,45};
	//int *p;
	p=&arr[4];
	for(i=0;i<5;i++)
		printf("%d\t %d\t",*(p-i),p[-i]);
	return 0;
}*/
	


/*#include<stdio.h>
int main(void)
{
	//int arr[5];
	int i,arr[5]={25,30,35,40,45},*p;
	//arr[5]={25,30,35,40,45};
	//int *p;
	p=arr;
	for(i=0;i<5;i++)
		printf("%d\t %d\t",*(p+i),p[i]);
	return 0;
}*/


/*#include<stdio.h>
int main(void)
{
	int i,arr[5]={25,30,35,40,45},*p=arr;
	
	for(i=0;i<5;i++)
	{
		(*p)++;//increment the value
		printf("%d\t",*p);
		p++;//increment the pointer
	}
	return 0;
}*/


/*#include<stdio.h>
int main(void)
{
	int i,arr[5]={25,30,35,40,45},*p=arr;
	
	for(i=0;i<5;i++)
	{
		++*p;//increment the value
		printf("%d\t",*p);
		p++;//increment the pointer
	}
	return 0;
}*/



/*#include<stdio.h>
int main(void)
{
	int i,arr[5]={25,30,35,40,45},*p=arr;
	
	for(i=0;i<5;i++)
	{
		//p++;//increment the pointer
		printf("%d\t",*p);
		
			(*p)++;//increment the value
			printf("%d\n",*p);
	}
	return 0;
}*/
