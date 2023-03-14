

#include<stdio.h>
#include<stdlib.h>
void read(int(* ptr)[],int r,int c);
void display(int(*ptr)[],int r,int c);


void main()
{
	int (*ptr)[6]=NULL;int i,j,r,c;
	//int M1[2][3];
	printf("enter r:\n");
	scanf("%d",&r);
	printf("enter c:\n");
	scanf("%d",&c);
	ptr=(int(*)[])malloc((r*c)*sizeof(int));
	read(ptr,r,c);
	display(ptr,r,c);
}


void read(int (*ptr)[16],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",&ptr[i][j]);
	}
}


void display(int (*ptr)[16],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
			printf("display %p \t %d   +30",&ptr[i][j],ptr[i][j]);
	}
}



