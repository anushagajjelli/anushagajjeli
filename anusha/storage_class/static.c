/*int main(void)
{
	int i,sum=0;
	for(i=0;i<5;i++)
	{
		int i=10;
		sum=sum+(++i);//sum=sum+ ++i;->o/p-55
	}
	printf("%d\n",sum);//output-55
	return 0;
}*/
	
	
/*int main(void)
{
	int i,sum=0;
	for(i=0;i<5;i++)
	{
		int i=10;
		sum=sum+i++;
	}
	printf("%d\n",sum);//o/p->50
	return 0;
}*/


/*int main(void)
{
	int i,sum=0;
	for(i=0;i<5;i++)
	{
		static int i=10;
		printf("%d\n value of i:",i);
		sum=sum+i++;
		printf("%d\n sum value:",i);
	}
	printf("%d\n",sum);//o/p->50
	return 0;
}*/

/*int main(void)
{
	int i,sum=0;
	for(i=0;i<5;i++)
	{
		static int i=10;
		printf("%d\n value of i:",i);
		sum=sum+ ++i;
		printf("%d\n sum value:",i);
	}
	printf("%d\n",sum);//o/p->50
	return 0;
}*/

#include<stdio.h>
main()
{
	display();
} 
static int x=5;















