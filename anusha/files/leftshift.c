#include<stdio.h>
main()
{
unsigned int x=0xffffffff;
x=x&(~(0x7<<18));
printf("%x",x);
}
