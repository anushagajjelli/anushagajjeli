#include<stdio.h>
int polindrome(char*cptr);
int main(int argc,char*argv[])
{
	int i,stat;
	for(i=0;i<argc;i++)
	{
		stat=polindrome(argv[i]);
		if(stat==0)
		{
			printf("%s\n",argv[i]);
		}
	}
}
int polindrome(char*cptr)
{
	int i,j;
	j=strlen(cptr);
	for(i=0,j=j-1;i<j;i++,j--)
	{
		if(cptr[i]!=cptr[j])
		 	return -1;
	}
	return 0;
}
	
		
