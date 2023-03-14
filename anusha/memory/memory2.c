#include<stdio.h>
main()
{
	unsigned int KB=1024;
	unsigned int MB=1024*KB;
	unsigned int str=0x00000000;
	printf("total size is 2MB\n");
	printf("total starting address and ending address %p to %p\n",str,(str+(2*(MB)-1)));
	printf("partition 1:512KB\n");
	printf("partition 1 starting and ending address %p to %p\n",str,(str+(512*KB)-1));
	printf("partition-1 A block starting and ending address %p to %p\n",str,str+(255*KB));
	printf("partition-1 B block starting and ending address %p to %p\n",str+(256*(KB)),((str+(512*KB))-1));

	printf("partition 2:512KB\n");
	printf("partition-2 starting and ending address %p to %p\n",(str+(512*KB)),(str+(1*(MB)-1)));
	printf("partition-2 A block starting and ending address %p to %p\n",str+(512*KB),str+(767*KB));
	printf("partition-2 B block starting and ending address %p to %p\n",(str+(768*KB)),((str+MB)-1));

	printf("partition 3:512KB\n");
	printf("partition 3 starting and ending address %p to %p\n",(str+MB),(str+MB+(512*KB)-1));
	printf("partition-3 A block starting and ending address %p to %p\n",str+MB,str+MB+(255*KB));
	printf("partition-3 B block starting and ending address %p to %p\n",str+MB+(256*(KB)),((str+MB+(512*KB))-1));

	printf("partition 4:512KB\n");
	printf("partition-4 starting and ending address %p to %p\n",(str+MB+(512*KB)),(str+(2*(MB)-1)));
	printf("partition-4 A block starting and ending address %p to %p\n",(str+MB+(512*KB)),(str+(MB)+(767*KB)));
	printf("partition-4 B block starting and ending address %p to %p\n",(str+(MB)+768*(KB)),((str+(2*MB))-1));
	unsigned int add;
	printf("enter a address");
	scanf("%x",&add);
	if((add>=str)&&(add<(2*(MB)))){
		if(add<(str+256*KB))
			printf("partition-1 A-block\n");
		else if(add<(str+512*KB))
			printf("partition 1-B block\n");
		else if(add<(str+768*KB))
			printf("partition 2-A block\n");
		else if(add<(str+MB))
			printf("partition 2-B block\n");
		else if(add<(str+MB+256*MB))
			printf("partition 3-A block\n");
		else if(add<(str+MB+512*KB))
			printf("partition 3-B block\n");
		else if(add<(str+MB+768*KB))
			printf("partition 4-A block\n");
		else
			printf("partition 4-B block\n");
		}
	else
		printf("invalid address");
} 

	
