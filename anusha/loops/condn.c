/*main()
{
	int x=5;
	int y;
	y=x++;
	printf("%d %d\n",x,y);
}*/

/*main()
{
	unsigned int x=0xAABBCCDD;
	unsigned int y;
	y=(char)x;
	printf("%x\n",y);
	y=x;
	printf("%x\n",y);
}*/

/*main()
{
	printf("%d\n",5>1);
	printf("%d\n",5<1);
	printf("%d\n",5.0/2);
	printf("%f\n",5.0/2);
	printf("%d\n",5==1);
	printf("%d\n",5>=1);
}*/

/*#include<stdio.h>
int main()
{
	int x;
	int y;
	int big;
	printf("enter the two inputs x:y\n");
	scanf("%d:%d\n",&x,&y);
	big=(x>y)?x:y;
	printf("%d\n",big);
	return 0;


}*/

/*main()
{
	int x=5;
	int y=9;
	(x>y)?printf("%d\n",x):printf("%d\n",y);
}*/

/*#include<stdio.h>
main()
{
	int x=6;
	int y=2;
	int big;
        big=(x<y)?y:x;
	printf("%d\n",big);
}*/

/*main()
{
	int x=4;
	int y=7;
	int z=2;
	int c;
        c=(z>y)?((z>x)?z:x):((y>x)?y:x);
	printf("%d",c);
}*/

/*#include<stdio.h>
main()
{
	int x=5;
	int div;
	div=(x%5==0)?printf("divisble by 5\n"):printf("not divisible by 5\n");
}*/

/*#include<stdio.h>
main()
{
	int x=15;
	((x<=9)||(x>=99))?printf("x is out of range"):printf("x is within the range");
}*/


/*#include<stdio.h>
main()
{
	int x;
        printf("enter a number");
        scanf("%d\n",&x);
	/*((x%3==0)&&(x%5==0))?printf("divisible by 3 and 5\n"):printf("not divisible by 3 and 5\n");*/
	/*((x%3!=0)||(x%5!=0))?printf("not divisible by 3 and 5\n"):printf("divisible by 3 and 5\n");
}*/







#include<stdio.h>
main()
{
	int a=6;
	int b=4;
	int c=2;
	int d=8;
	int big;
	big=(((a>b)?a:b)>((c>d)?c:d))?((a>b)?a:b):((c>d)?c:d);
	printf("%d\n",big);
}

