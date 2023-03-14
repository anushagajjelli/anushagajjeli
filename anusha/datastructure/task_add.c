#include<stdio.h>
void main()
{
	char opt;
	int x,y;
	scanf("%d %d",&x,&y);
	__fpurge(stdin);
	scanf("%c",&opt);
	switch(opt)
	{
		case '+':printf("%d",x+y);
			break;
	}
}
		
