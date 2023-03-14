//wap to perform swapping with using swap function


#include<stdio.h>
struct student 
{
	char name[32];
	int id_no;
	char gen;
	char grade;
};

main()
{
	struct student s1={"Anu",1,'F','A'};
	struct student s2={"siri",2,'F','A'};
	struct student temp;
	temp=s1;
	s1=s2;
	s2=temp;
	printf("%p-%p-%p-%p\n",s1.name,&s1.id_no,&s1.gen,&s1.grade);
	printf("%s-%d-%c-%c\n",s1.name,s1.id_no,s1.gen,s1.grade);
	printf("%p-%p-%p-%p\n",s2.name,&s2.id_no,&s2.gen,&s2.grade);
	printf("%s-%d-%c-%c\n",s2.name,s2.id_no,s2.gen,s2.grade);
	printf("\n");
}

