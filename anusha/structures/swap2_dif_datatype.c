//wap to swap the data of one struct to another struct by using different datatype

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
	struct student s1={"Anu",1,'F','A'};
	struct student s2={"Chinnu",2,'F','A'};
	char str_temp[32];
	int temp_id_no;
	char temp_gen;
	char temp_grade;
	strcpy(str_temp,s1.name);
	strcpy(s1.name,s2.name);
	strcpy(s2.name,str_temp);
	
	temp_id_no=s1.id_no;
	s1.id_no=s2.id_no;
	s2.id_no=temp_id_no;
	
	temp_gen=s1.gen;
	s1.gen=s2.gen;
	s2.gen=temp_gen;
	
	temp_grade=s1.grade;
	s1.grade=s2.grade;
	s2.grade=temp_grade;
	
	printf("%p-%p-%p-%p\n",s1.name,&s1.id_no,&s1.gen,&s1.grade);
	printf("%s-%d-%c-%c\n",s1.name,s1.id_no,s1.gen,s1.grade);
	printf("%p-%p-%p-%p\n",s2.name,&s2.id_no,&s2.gen,&s2.grade);
	printf("%s-%d-%c-%c\n",s2.name,s2.id_no,s2.gen,s2.grade);
}
	
	
	
