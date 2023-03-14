//example program to structure updating the student details with other student


#include<stdio.h>
struct student 
{
	char name[32];
	unsigned int id_no;
	char gen;
	char grade;
};

main()
{
		struct student s={.id_no=1,.name="anu",.grade='S',.gen='F',};
		printf("%s-%d-%c-%c\n",s.name,s.id_no,s.gen,s.grade);
		printf("%d\n",sizeof(s));
		printf("%d\n",sizeof(struct student));
		printf("%p\n",&s);
		scanf("%s",&s.name);
		__fpurge(stdin);
		scanf("%d",&s.id_no);
		__fpurge(stdin);
		scanf("%c",&s.gen);
		__fpurge(stdin);
		scanf("%c",&s.grade);
		printf("%s-%d-%c-%c\n",s.name,s.id_no,s.gen,s.grade);
}

