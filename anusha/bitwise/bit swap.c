#include<stdio.h>
main()
{
	unsigned char x;
	printf("enter a input");
	scanf("%c",&x);
	if(((x>=65)&&(x<=90))||((x>=97)&&(x<=122))){
		if((x>=65)&&(x<=90))
			printf("%c\n",x=x+32);
		else if((x>=97)&&(x<=122))
			printf("%c\n",x=x-32);
	}
	else
		printf("special character");
}

