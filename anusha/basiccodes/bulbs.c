/*#include<stdio.h>
main()
{
int s=0;
int b = 0xff;
	s = s&b;
	printf("%d\n",s);
	s = s|b;
	printf("%d\n",s);
	return 0;
}*/



/*#include<stdio.h>
main()
{
	unsigned x=0;
	printf("%d\n",x);
	printf("all bulbs are in off state");
	unsigned x=255;
	printf("%d\n",x);
	printf("all bulbs are in on state");
}*/

#include<stdio.h>
main()
{
	unsigned char x=0;
	printf("%d\n",x);
	x=~x;
	printf("%d\n",x);
}
