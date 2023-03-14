
/*#include<stdio.h>
int x=5;
main()
{
	x=15;
	printf("%d\n",x);//prints the output as 10
}*/


/*#include<stdio.h>
main()
{
	x=10;
	printf("%d\n",x);//compilaton error x is undeclared 
}
int x=5;//x scope will start here*/



/*main()
{
	int x=10;
	if(x<=10)
	{
		main();
		printf("%d\n",x);//segmentation fault
		x++;
	}
}*/


main()
{
	int x=1;
	for(x=1;x<=10;x++)
	{
		int x=15;//this x variable scope is different from x=1 in main
		printf("%d\n",x);//x=15 will print for 10 times
		x++;
	}
}
	


