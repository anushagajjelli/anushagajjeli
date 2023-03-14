//example program to structures details of employee


#include<stdio.h>
struct employee 
{
	char name[32];
	unsigned int id_no;
	float salary;
	char gen;
	char grade;
};

main()
{
		struct employee e={"anu",1,1200000,'F','S'};
		printf("%p-%p-%p-%p-%p\n",e.name,&e.id_no,&e.salary,&e.gen,&e.grade);
		printf("%s-%d-%f-%c-%c\n",e.name,e.id_no,e.salary,e.gen,e.grade);
		printf("%d\n",sizeof(e));
		printf("%d\n",sizeof(struct employee));
		printf("%p\n",&e);
		scanf("%s",&e.name);
		__fpurge(stdin);
		scanf("%d",&e.id_no);
		__fpurge(stdin);
		scanf("%f",&e.salary);
		__fpurge(stdin);
		scanf("%c",&e.gen);
		__fpurge(stdin);
		scanf("%c",&e.grade);
		printf("%s-%d-%f-%c-%c\n",e.name,e.id_no,e.salary,e.gen,e.grade);
		printf("%p-%p-%p-%p-%p\n",e.name,&e.id_no,&e.salary,&e.gen,&e.grade);
}

