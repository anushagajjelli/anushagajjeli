//wap to perform each character for a given string

#include<stdio.h>
#include<stdlib.h>
int j=0;
char *src[5];
void display();
main()
{
	//char *src[5];
	char *ptr;
	char c;
	int i=1;
	printf("enter the character\n");
	__fpurge(stdin);
	scanf("%c",&c);
	ptr=malloc(1*sizeof(char));
	ptr[0]=c;
	while(c!='\n')
	{
		printf("enter the character\n");
		__fpurge(stdin);
		scanf("%c",&c);
		ptr=realloc(ptr,i*sizeof(char));
		ptr[i]=c;
		i++;
	}
	ptr[i-1]='\0';
	src[j]=ptr;
	 printf("%s",src[j]);
	j++;
	display();


}

void display()
{
	int i;
	for(i=0;i<j;j++)
		printf("%s\n",src[i]);
}
