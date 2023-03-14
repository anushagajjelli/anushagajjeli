//wap on double pointer

main()
{
	int x=15;
	int * ptr=&x;
	int **dptr=&ptr;
	printf("%p\n",&x);//&ptr
	printf("%d\n",sizeof(&x));
	printf("%d\n",x);
	printf("%d\n",sizeof(x));
	printf("%p\n",ptr);
	printf("%d\n",ptr);
	printf("%d\n",sizeof(ptr));
	printf("%p\n",&ptr);//ptr
	printf("%d\n",sizeof(&ptr));
	printf("%d\n",*ptr);
	printf("%p\n",*ptr);
	printf("%d\n",sizeof(*ptr));
	printf("%p\n",dptr);
	printf("%d\n",sizeof(dptr));
	printf("%p\n",&dptr);
	printf("%d\n",sizeof(&dptr));
	printf("%p\n",*dptr);
	printf("%d\n",sizeof(*dptr));
	printf("%p\n",**dptr);
	printf("%d\n",**dptr);
	printf("%d\n",sizeof(**dptr));
} 
	
	
	
