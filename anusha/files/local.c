#include<stdio.h>
main()
{
	 int x=30;
	int y=45;
	printf("%d %d\n",x,y);
	{
		int y=60;
		   y=65;
		   printf("%d\n",y);
		   {
			   int z=500;
			   printf("%d\n",z);
		   }
	}
	x=44;
	printf("%d\n",x);
}


