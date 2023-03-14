#include<stdio.h>
void func(char,void(*fp)(float));
void func1(float);
int main()
{
	printf("fun main()called\n");
	func('a',func1);
}
void func(char b,void(*fp)(float fs))
{

printf("functio func called\n");
(*fp)(8.5);
}
void func1 (float f)
{
	printf("%f   function fun1 called\n");
}
