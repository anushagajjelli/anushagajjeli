#include<stdio.h>
main()
{
	unsigned int KB=1024;
	unsigned int MB=1024*KB;//mb=1024*1024
	unsigned int add;
	unsigned int str=0x00000000;
	printf("total size is 2MB\n");
	printf("total starting address and ending address %p to %p\n",str,(str+(2*(MB)-1)));
	printf("partition 1:1MB\n");
	printf("partition 1 starting and ending address %p to %p\n",str,(str+(MB)-1));
	printf("partition-1 A block starting and ending address %p to %p\n",str,str+(511*KB));
	printf("partition-1 B block starting and ending address %p to %p\n",str+(512*(KB)),((str+(MB))-1));
	printf("partition 2:1MB\n");
	printf("partition-2 starting and ending address %p to %p\n",(str+(MB)),(str+(2*(MB)-1)));
	printf("partition-2 A block starting and ending address %p to %p\n",str+(MB),(str+(MB)+(511*KB)));
	printf("partition-2 B block starting and ending address %p to %p\n",(str+(MB)+512*(KB)),((str+(2*MB))-1));
	printf("enter a address");
	scanf("%x",&add);
	if((add>=str)&&(add<(2*(MB)))){
		if(add<(str+512*KB))
			printf("partition-1 A-block\n");
		else if(add<(str+MB))
			printf("partition 1-B block\n");
		else if(add<(str+MB+(512)*(KB)))
			printf("partition 2-A block\n");
		else
			printf("partition 2-B block\n");
		}
	else
		printf("invalid address");
}
	
