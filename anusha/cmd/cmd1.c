#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void binary(char* ptr,int num);
void ascending_order(char* ptr,int n);
void descending_order(char* ptr,int n);
int palindrome(char* ptr);


main(int argc,char *argv[])
{
	int ptr;
	int i,j,temp,sum=0;
	//char opt;

	if(argc<2)
	{
		printf("Invalid no.of inputs:");
		exit(0);
	}
	
	else if(argv[1][0]!='-')
		{
			printf("Invalid string without hyphen:");
			exit(1);
		}
			
	else if((argv[1][1]!='a')&&(argv[1][1]!='b')&&(argv[1][1]!='c')&&(argv[1][1]!='d'))
			{
				printf("Invalid option:");
				exit(2);
			} 
				
					ptr=(int*)malloc(4*sizeof(int));
					if(ptr==NULL)
					{
						printf("failed to access memory in heap\n");
						exit(1);
					}
						for(i=2;i<6;i++)
						{
							for(j=0;j<2;j++)
							{
								if(argv[i][j]>='0'&&argv[i][j]<='9')
								{
									temp=argv[i][j]-48;
									sum=sum*10+temp;
							
								}
							}
							ptr[i-2]=sum;
						}
						
						switch(argv[1][1])
						{
							case 'a':binary(argv,4);
								break;
							
							case 'b':
								ascending_order(ptr,4);
									
								
								break;
						
							case 'c':descending_order(argv,6);
								break;

							case 'd':{
									int i,j,rev;
									for(i=0;i<argc;i++)
									{
										rev=palindrome(argv[i]);
										if(rev==0)
											printf("%s\n",argv[i]);
									}
								}
								
								break;
							

						}
	
}

void binary(char* ptr,int num)
{

	int i,k=1,sum=0,temp;
	
	//printf("DEC\tBINARY\n");
	for(i=2;i<6;i++)
	{
		num=ptr[i];
		sum=0;
		k=1;
		while(num>0)
		{
			
			temp=num%2;
			num=num/2;
			sum=sum+k*temp;
			k=k*10;
		}
		//if()
		//{
		//	neg=~(sum+1);
               //			printf("%d\t %d\n",ptr[i],neg);
		//}
		//else
			//ptr[i]=sum;
			//printf("%d\t",sum);
			printf("%d\t %d\n",ptr[i],sum);
	}
}



void ascending_order(char* ptr,int n)
{
	int i,j,temp;
	for(i=2;i<6;i++)
	{
		for(j=i+1;j<6;j++)
		{
			if(ptr[i]>ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	printf("ascending order:");
	for (i = 2; i<6; i++) 
        printf("%s", ptr[i]);
}


void descending_order(char* ptr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ptr[i]<ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
	 printf("descending order:");
	for(i=0;i<n;i++)
		printf("%s",ptr[i]);
}
		


int palindrome(char* ptr)
{
	int i,j,l;
	l=strlen(ptr);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		if(ptr[i]!=ptr[j])
		return -1;
	}
	return 0;
}
































