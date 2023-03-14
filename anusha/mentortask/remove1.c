void remove_spaces(char* ptr)
{
	int i,j,l;
	l=strlen(ptr);
	printf("before removing spaces %d",l);
	for(i=0;i<l;i++)
	{
		if(ptr[0]==' ')
		{
			for(i=0;i<(l-1);i++)
			{
				ptr[i]=ptr[i+1];
			}
				ptr[i]='\0';
				l--;
				i=-1;
				continue;
		}
		if((ptr[i]==' ')&&(ptr[i+1]==' '))
		{
			for(j=i;j<(l-1);j++)
			{
				ptr[j]=ptr[j+1];
			}
			ptr[j]='\0';
			l--;
			i=-1;
		}
	}
	printf("after removing spaces %d",l);
	printf("%s",ptr);
}

