#include<stdio.h>
#include<string.h>
struct details
{
	char name[32];
	int age;
	char city[32];
};
void main()
{
	int i,min,j;
	struct details temp;
	struct details ptr[3];
	for(i=0;i<3;i++)
	{
		printf("Enter name of %d:",i+1);
		scanf("%s",ptr[i].name);
		printf("Enter age of %d:",i+1);
		scanf("%d",&ptr[i].age);
		printf("Enter city of %d:",i+1);
		scanf("%s",ptr[i].city);
	}
	for(i=0;i<3;i++)
	{
		min=i;
		for(j=i+1;j<3;j++)
		{
			if(ptr[min].age<ptr[j].age)
			{
			    	temp.age=ptr[min].age;
			    	ptr[min].age=ptr[j].age;
			    	ptr[j].age=temp.age;

				strcpy(temp.name,ptr[min].name);
				strcpy(ptr[min].name,ptr[j].name);
				strcpy(ptr[j].name,temp.name);

				strcpy(temp.city,ptr[min].city);
                                strcpy(ptr[min].city,ptr[j].city);
                                strcpy(ptr[j].city,temp.city);


			}
		}
	}
	//printf("%d",ptr[0].age);
	printf("elder details -%s %d %s\n",ptr[0].name,ptr[0].age,ptr[0].city);
}
