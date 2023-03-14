/*x-or opration---toggle the value*/

/*#include<stdio.h>
main()
{
unsigned int x=0xf0;
x=x|(0x08);
printf("%x",x);
}*/

/*#include<stdio.h>
main()
{
unsigned char x=0x6c;
x=x^(0x00);
printf("%x",x);
}*/

#include<stdio.h>
main()
{
unsigned int x=0x6f;
x=x^(~(0x08));
printf("%x",x);
}



/*#include<stdio.h>
main()
{
unsigned int x=0x6f;
x=x^(0x24);
printf("%x",x);
}*/

/*or operation--set a bit*/

/*#include<stdio.h>
main()
{
unsigned int x=0xff;
x=x|(~(0x00));
printf("%x",x);
}*/


/*#include<stdio.h>
main()
{
unsigned char x=0x6a;
x=x|(~(0xee));
printf("%x",x);
}*/

/*and operation-clear a bit*/


/*#include<stdio.h>
main()
{
unsigned int x=0x36;
x=x&(0xeb);
printf("%x",x);
}*/
