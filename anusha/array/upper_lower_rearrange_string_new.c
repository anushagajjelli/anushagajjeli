#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

void main()
{
        int i,j,len;
        char *src,*res=NULL,temp;
        src=malloc(SIZE*sizeof(char));
        res=malloc(SIZE*sizeof(char));
        if((src==NULL)||(res==NULL))
        {
                printf("Failed to allocate the memory\n");
                exit(1);
        }

        printf("Enter the string:");
        scanf("%[^\n]s",src);

	strcpy(res,src);

	len=strlen(res);
	len--;
	
	for(j=0;j<len;j++)
	{
		for(i=0;i<len;i++)
		{
			if((res[i]>=65)&&(res[i]<=90))
				continue;
			else
			{	
				temp=res[i];
				res[i]=res[i+1];
				res[i+1]=temp;
			}	
		}
	}
	printf("%s\n",res);
	free(src);
	free(res);

}


