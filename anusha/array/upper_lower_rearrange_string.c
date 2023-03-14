#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
void main()
{
	int i,j=0;
	char *src,*res;
	src=malloc(SIZE*sizeof(char));
	res=malloc(SIZE*sizeof(char));
	if((src==NULL)||(res==NULL))
	{
		printf("Failed to allocate the memory\n");
		exit(1);
	}

	printf("Enter the string:");
	scanf("%[^\n]s",src);

	for(j=0,i=0;src[i]!='\0';i++)
	{
		if((src[i]>=65)&&(src[i]<=90))
		{
			res[j]=src[i];
			j++;
		}
	}
	res[j]=' ';
	//j++;

	for(j=j+1,i=0;src[i]!='\0';i++)
	{
		if((src[i]>=97)&&(src[i]<=122)){
			res[j]=src[i];
			j++;
		}
	}
	printf("%s\n",res);
	free(src);
	free(res);

}
