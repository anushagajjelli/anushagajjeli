#include<stdio.h>
main()
{
	unsigned int add;
	unsigned int MB,GB;
	MB=(1024*1024);
	GB=(1024*1024*1024);//total space in gb
	printf("complete address from0x00000000 to %p\n",((GB)-1));
	printf("partition -1 starting and ending address %p to %p\n",(512*(MB)),((GB)-1));
	printf("partition-2 starting and  ending address %p to %p\n",(0x00000000),(511*(MB)));
	printf("partition-2 block b address from 0x00000000 to %p\n",(256*(MB)-1));
	printf("partition-2 block a address from %p to %p\n",(256*(MB)),(512*(MB)-1));
	printf("partition-1 block b address from %p to %p\n",(512*(MB)),(768*(MB)-1));
	printf("partition-1 block b address from %p to %p\n",(768*(MB)),((GB)-1));
	printf("enter the hexadecimal address:");
	scanf("%x",&add);
	printf("%x\n",add);
	printf("%p\n",&add);
	if((add>=0x00000000)&&(add<("%p",GB)))
	{
		if(add<("%p",(256*(MB))))
			printf("partition -2 b-block\n");
		else if(add<("%p",(512*(MB))))
			printf("partition-2 A-block\n");
		else if(add<("%p",(768*(MB))))
			printf("partition-1 B-block\n");
		else
			printf("partition-1 A-block\n");
	}
	else
		printf("enter invalid address");
}
