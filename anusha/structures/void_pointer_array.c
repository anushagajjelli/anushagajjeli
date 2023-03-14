
#include<stdio.h>
struct book
{
	//char name[32];
	//int nop;
	double price;
	//int nop;
	char name[32];
	int nop;
};

void main()
{
	struct book s;
	printf("total size-%ld\n",sizeof(s));
	int i;
	//struct book b[3]={{"c",500,400},{"DS",700,1000},{"C++",300,600}};
	/*void *ptr=b;
	for(i=0;i<3;i++)
	{
		printf("%s\n",((struct book*)ptr)[i].name);
		printf("%d\n",((struct book*)ptr)[i].nop);
		printf("%f\n",((struct book*)ptr)[i].price);
	}*/
}
	
