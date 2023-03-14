

#include<stdio.h>
#include<stdio_ext.h>
int mystrlen(char*);
char* mystrrev(char *src);
char* mystrcpy(char* dst,char* src);
int mystrcmp(char *,char *);
int int_ascii(int num);
char ascii_int(char* src);
int mystrcmpy(char*,char*,int);//search string
void count_string(char*);
int palindrome(char *src);
void concatenate(char*,char*);	
	
/*int (*lptr)(char*);
char* (*rptr)(char* src);
char* (*cptr)(char* dst,char* src);
int (*fptr)(char *,char *);
int (*iptr)(int num);
char* (*aptr)(char* src);
int (*sptr)(char*,char*,int);//search string
void (*tptr)(char*);
int (*pptr)(char *src);
void (*gptr)(char*,char*);*/

main()
{
	int opt;
	while(1)
	{
		printf("\nselect  the options\n0.exit\n1.stringlength\n2.string reverse\n3.string copy\n4.string comparison\n5.int_ascii\n6.ascii_int\n7.search string\n8.count the string\n9.palindrome\n 10.concatenation\n");
		printf("ENTER THE OPTION:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			case 1:{
					char src[10];
					int l;
					printf("enter the string:");
					scanf("%s",src);
					__fpurge(stdin);
					void* vptr;
					vptr=mystrlen;
					l=((int(*)(char*))vptr)(src);
					printf("the string length is %d",l);
					break;
				}
					

			case 2:{
					char src[30];
					char* rev;
					printf("enter the string:");
					scanf("%s",src);
					__fpurge(stdin);
					void* rptr;
					rptr=mystrrev;
					rev=((char*(*)(char*))rptr)(src);
					printf("%s\n",rev);
					break;
				}
	
			case 3:{
					char src[20];
					char dst[20];
					char* str;
					printf("enter the string:");
					scanf("%s",src);
					__fpurge(stdin);
					void* cptr;
					cptr=mystrcpy;
					str=((char*(*)(char*,char*))cptr)(dst,src);
					printf("%s\n",str);
					break;
				}

			case 4:{
					int str;
					char src1[20];
					char src2[20];
					printf("enter the first string:");
					scanf("%s",&src1);
					printf("enter the second string:");
					scanf("%s",&src2);
					__fpurge(stdin);
					void* fptr;
					fptr=mystrcmp;
					str=((int(*)(char*,char*))fptr)(src1,src2);
					if(str==0)
						printf("the strings are same:");
					else
					printf("the strings are not same:");
					break;
				}
	
			case 5:{
					int src[100];
					int num,i,temp,sum=0,rem;
					printf("enter a integer number:");
					scanf("%s",&src);
					__fpurge(stdin);
					void* iptr;
					iptr=int_ascii;
					((int(*)(int))iptr)(src);
					printf("%s",src);
					break;
				}

			case 6:{
					
					int* k;
					char src[10];
					printf("enter the ascii value:");
					scanf("%s",src);
					__fpurge(stdin);
					void* aptr;
					aptr=ascii_int;
					k=((char(*)(char*))aptr)(src);
					printf("%d\n",k);
					break;
				}
			
			case 7:{
				
					int i,j,k,cmp=0,count=0;
					char src[100];
					char dst[100];
					printf("enter the string:");
					__fpurge(stdin);
					scanf("%[^\n]s",src);
					__fpurge(stdin);
					printf("enter the string to be searched:");
					scanf("%[^\n]s",dst);
					__fpurge(stdin);
					void* sptr;
					sptr=mystrcmpy;
					i=strlen(src);
					j=strlen(dst);
					printf("%d-%d\n",i,j);
					for(k=0;k<=(i-j);   )
					{
						cmp=((int(*)(char*,char*,int))sptr)(&src[k],dst,j);
						if(cmp==0)
						{
							count++;
							k=k+j;
						}
						k++;
					}
					if(count!=0)
						printf("string is found-%d\n",count);
					else
						printf("not found\n");
					break;
				}
		
			case 8:{
					char src[100];
					printf("enter the string:");
					__fpurge(stdin);
					scanf("%[^\n]s",src);
					void* tptr;
					tptr=count_string;
					((void(*)(char*))tptr)(src);
					break;
				}
	
			case 9:{
					int k,i,j,count=0;
					char src[10];
					printf("enter the inputs:");
					scanf("%s",&src);
					__fpurge(stdin);
					void* pptr;
					pptr=palindrome;
					((int(*)(char*))pptr)(src);
					break;
				}
	
			case 10:{
					__fpurge(stdin);
					char a[30];
					char b[30];
					printf("enter the string:\n");
					scanf("%[^\n]s",&a);
					__fpurge(stdin);
					printf("enter the string to be searched:\n");
					scanf("%[^\n]s",&b);
					__fpurge(stdin);
					void* gptr;
					gptr=concatenate;
					((void(*)(char*,char*))gptr)(a,b);
					break;
				}
			default:printf("INVALID OPTION\n");
			
		}
		printf("\n....................................\n");
	}
	
}
	

int mystrlen(char* src)
{
	int i;
	for(i=0;src[i]!='\0';i++);
		return i;
}



char* mystrrev(char *src)
{
	int i,j,l,temp;
	l=strlen(src);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		temp=src[i];
		src[i]=src[j];
		src[j]=temp;
	}
	return src;
}
	


char* mystrcpy(char* dst,char* src)
{
	int i;
	for(i=0;src[i]!='\0';i++)
	{
		dst[i]=src[i];
		//dst[i]='\0';
	}
	dst[i]=src[i];
	//printf(" in function %s",dst[i]);
	return dst;
}



int mystrcmp(char* src1,char* src2)
{
	int i,l1,l2;
	if((src1==NULL)||(src2==NULL))
		return -1;
	l1=strlen(src1);
	l2=strlen(src2);
	if(l1!=l2)
	{
		return -1;
	}
	for(i=0;src1[i]!='\0';i++)
	{
		if(src1[i]!=src2[i])
			return -1;
	}
	return 0;
}
	


int int_ascii(int num)
{
	int temp,sum=0,rem;
	int src[100],i;
	for(i=0;src[i]!='\0';i++)
	{	
		if((src[i]>=0)&&(src[i]<=9))
		{
			//rem=num%10;
			temp=src[i]+48;
			sum=sum*10+temp;
		}
		
	}
	
	return sum;
}


char ascii_int(char* src)
{
	int i,l,temp,sum=0;
	l=strlen(src);
	for(i=0;src[i]!=0;i++)
	{
		if((src[i]>='0')&&(src[i]<='9'))
		{
			temp=src[i]-48;
			sum=sum*10+temp;
		}
	}
	return sum;
}


int mystrcmpy(char* cmp1,char* cmp2,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(cmp1[i]!=cmp2[i])
			return 1;
	}
	return 0;
}


void count_string(char* src)
{
	int i,j,count;
	for(i=0;src[i]!='\0';i++)
	{
		if(src[i]==' ')
		{
			continue;
		}
		count=1;
		for(j=i+1;src[j]!='\0';j++)
		{
			if(src[i]==src[j])
			{
				count++;
				src[j]=' ';
			}
		}
		printf("%c-%d\n",src[i],count);
	}
}





int palindrome(char *src)
{
	int i,j,count=0;	
	
	for(i=0,j=(strlen(src)-1);i<j;i++,j--)
	{
		if(src[i]!=src[j])
		{
			count=0;
		}
		else if(src[i]==src[j])
		{
			count=1;
		}
		//return count;
	}
	if(count==1)
		printf("palindrome:");
	else
		printf("not palindrome:");
}


void concatenate(char* ptr1,char* ptr2)
{
	int l1,l2,len,i,j;
	l1=strlen(ptr1);
	l2=strlen(ptr2);
	len=l1+l2;
	for(i=l1,j=0;i<len;i++,j++)
	{
		ptr1[i]=ptr2[j];
	}
	ptr1[i]='\0';
		printf("%s\n",ptr1);
	
}






