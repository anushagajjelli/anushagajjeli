/*#include<stdio.h>
main()
{
	int x=1;
	int y=0;
	((x>0)||(y++))?printf("true"):printf("false");
	printf("%d\n %d\n",x,y);

}*/


/*#include<stdio.h>
main()
{
	int x=1;
	((x>0)||(printf("welcome"))?printf("true"):printf("false");
}*/


#include<stdio.h>
main()
{
	int x=10;
	int y=20;
	int big;
	(x>y)?(printf("biggest value is \n"),printf("%d\n",x)),
			(printf("biggest value is \n"),printf("%d\n",y));
}
