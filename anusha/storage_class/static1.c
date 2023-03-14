/*int x=89;
void func1(int x);
void func2(void);
int main(void)
{
	//int x=89;
	func1(x);
	//++x;
	printf("%d\t",x);
	func2();
	printf("%d\n",x);
	return 0;
}
void func1(int x)
{
	++x;
}
void func2(void)
{
	++x;
}*/

#include<stdio.h>
static int x=5;
void display()
{
	//static int x=5;
	printf("%d\n",x);
}
