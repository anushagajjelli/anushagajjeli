//wap to print the i/p:anusha gajjelli o/p:AnushA GajjellI

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	char buf[100];
	int l,i,j=0,k=0;
	printf("Enter the string:");
	scanf("%[^\n]s",buf);
	l=strlen(buf);
	for(i=0;i<l;i++)
	{
		if((buf[0]>=97)&&(buf[0]<=122))
			buf[0]=buf[0]-32;
		else if((buf[i]==' ')||(i==l-1))
		{
				if(i==l-1)
				{
					if((buf[i]>=97)&&(buf[i]<=122))
                                           
						buf[i]=buf[i]-32;
				}
				else
				{

					k=i-1;
					j=i+1;

					if((buf[k]>=97)&&(buf[k]<=122))
					{
						buf[k]=buf[k]-32;
					//	printf("2");
					}
					if((buf[j]>=97)&&(buf[j]<=122))
					{
						buf[j]=buf[j]-32;
					//	printf("1");
					}
				}
			}
		}
	printf("%s\n",buf);
}





		

