//method 2 for swapping

#include<stdio.h>
#include<string.h>
struct student 
{
	char name[32];
	int id_no;
	char gen;
	char grade;
};

main()
{
	struct student s1={"Minnu",1,'F','A'};
	struct student s2={"Bittu",2,'F','A'};
	struct student temp;
	strcpy(temp.name,s1.name);
	strcpy(s1.name,s2.name);
	strcpy(s2.name,temp.name);
	
	/*temp.name = s1.name;
	s1.name = s2.name;
	s2.name =temp.name;*/
	
	temp.id_no=s1.id_no;
	s1.id_no=s2.id_no;
	s2.id_no=temp.id_no;
	
	temp.gen=s1.gen;
	s1.gen=s2.gen;
	s2.gen=temp.gen;
	
	temp.grade=s1.grade;
	s1.grade=s2.grade;
	s2.grade=temp.grade;
	
	printf("%p-%p-%p-%p\n",s1.name,&s1.id_no,&s1.gen,&s1.grade);
	printf("%s-%d-%c-%c\n",s1.name,s1.id_no,s1.gen,s1.grade);
	printf("%p-%p-%p-%p\n",s2.name,&s2.id_no,&s2.gen,&s2.grade);
	printf("%s-%d-%c-%c\n",s2.name,s2.id_no,s2.gen,s2.grade);
}	
