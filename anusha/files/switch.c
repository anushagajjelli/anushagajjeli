#include<stdio.h>
main()
{
	unsigned int opt;
	unsigned char c,sub_opt;
	printf("enter the number");
		//scanf("%d",&x);
	switch(opt)
	{
case 1:printf("select the options to perform ascii to integer and upper to lowercase\na.upper to lowercase\nb.lower to uppercase\nc.ascii to integer\nd.integer to ascii");
		scanf("%c",&sub_opt);
		__fpurge(stdin);
		printf("enter the number");
		//scanf("%d",&x);
		switch(opt)
		{
			case 'a':printf("enter a character\n");
				scanf("%c",&c);
  				if((c>=65)&&(c<=90))
				{
					printf("%c->%c",c,(c+32));			
				}
				break;
			
			case 'b':printf("enter a character\n");
				scanf("%c",&c);
				if((c>=97)&&(c<=122))
				{
					printf("%c->%c",c,(c-32));			
				}
				break;
			
			case 'c':printf("enter a ascii value\n");
				scanf("%c",&c);
				if((c>=48)&&(c<=57))
				{
					printf("%c->%d",c,(c-48));			
				}
				break;

			case 'd':printf("enter a integer value\n");
				scanf("%c",&c);
				if((c>=0)&&(c<=9))
				{
					printf("%d->%c",c,(c+48));			
				}
				break;
			default:printf("invalid opt\n");
		}
	}
	
}

