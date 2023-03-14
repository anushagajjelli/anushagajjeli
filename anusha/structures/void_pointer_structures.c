//wap for a structure using void pointer

#include<stdio.h>
struct book
{
	char name[32];
	int nop;
	float price;
};

main()
{
	struct book b={"c",550,300};
	void *ptr;
	ptr=&b;//also can write as void *ptr=&b
	printf("%s\n",((struct book*)ptr)->name);
	printf("%d\n",((struct book*)ptr)->nop);
	printf("%f\n",((struct book*)ptr)->price);
}
