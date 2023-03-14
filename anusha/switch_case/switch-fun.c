/*wap to perform bitwise ,mathematical operations,swapping variables,characters and fibonacci series in switchcases using the functions*/

#include<stdio.h>
int replace_one_zero_one(int);
int count_zeros(int);
int binary_output(int);
int swap_bits(int);
int sum_digits(int);
int reverse_integer(int);
int binary_decimal(int);
int decimal_binary(int);
int swap_twovariables(int a,int b);
int swap_three(int a,int b);
int swap_bitwise(int x,int y);
char upper_lower(char);
char lower_upper(char);
char ascii_integer(char);
int integer_ascii(int);
int fibonacci_series(int);	





/*bitwise operations*/
int replace_one_zero_one(int x)
{
	int bit=0x0,count=0,i;
	for(i=0;i<=(31-3);i++)
	{
		if(((x&(0x7<<i))>>i)==(0x5))
		{
			bit=(bit|(0x7<<i));
			//count++;
		}
	}
	return bit;

	//printf("count is %d",count);;
}



int count_zeros(int y)
{
	int zero=0,one=0,bit;
	for(bit=31;bit>=0;bit--)
	{
	if((y&0x1<<bit)==0)
		zero++;
	else
		one++;
	}
	printf("zeros %d\n ones %d\n",zero,one);		
	
}


int binary_output(int z)
{
	int bit;
	for(bit=31;bit>=0;bit--)
	{
		if((z&0x1<<bit)==0)
			printf("0");
		else
			printf("1");
	}
}



int swap_bits(int n)
{
	int i,j;
	for(i=0,j=31;i<j;i++,j--)
	if((n&0x1<<i)^(n&0x1<<j))
		{
			n=(n&(~((0x1<<i)|(0x1<<j))))|((n&0x1<<i)<<(j-i))|((n&0x1<<j)>>(j-i));
		}
			printf("%x\n",n);
}

/*mathematical operations*/
int sum_digits(int num)
{
	int temp=num,rem,sum=0;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum+rem;
	}
	return sum;
	
}					

	
int reverse_integer(int num)
{
	int temp=num,rem,sum=0;
	while(temp!=0)
	{
		rem=temp%10;
		temp=temp/10;
		sum=sum*10+rem;
	}
	return sum;
	
}


int binary_decimal(int bin)
{
	int temp=bin,rem,dec=0,i=1;
	while(temp!=0)
	{
		rem=temp%10;
		if(rem>1)
			return -1;
		dec=dec+i*rem;
		i=i*2;
		temp=temp/10;
	}
	return dec;
}



int decimal_binary(int dec)
{
	int temp=dec,rem,bin=0,i=1;
	while(temp!=0)
	{
		rem=temp%2;
		if(rem>1)
			return -1;
		bin=bin+i*rem;
		i=i*10;
		temp=temp/2;
	}
	return bin;
}


/*swapping*/

int swap_twovariables(int a,int b)
{
	//int a,int b;
	printf("before swapping %d %d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("after swapping %d %d",a,b);
}


int swap_three(int a,int b)
{
	//int a,int b; 
	int c;
	printf("before swapping %d %d\n",a,b);
	c=a;
	a=b;
	b=c;
	printf("after swapping %d %d",a,b);
}

int swap_bitwise(int x,int y)
{
	//int x,int y;
	printf("before swapping %d %d\n",x,y);
	x=x^y;
	y=x^y;
	x=x^y;
	printf("after swapping %d %d",x,y);
}


/*characters*/

char upper_lower(char c)
{
	//char c;
	if((c>=65)&&(c<=90))
	{
		printf("%c->%c\n",c,(c+32));			
	}
	else
	printf("enter a valid input\n");
}


char lower_upper(char x)
{
	//char x;
	if((x>=97)&&(x<=122))
	{
		printf("%c->%c\n",x,(x-32));			
	}
	else
	printf("enter a valid input\n");
}	


char ascii_integer(char y)	
{
	//char y;
	if((y>=48)&&(y<=57))
	{
		printf("%c->%d\n",y,(y-48));			
	}
	else
	printf("enter a valid input\n");
}


int integer_ascii(int z)
{
	//int z;
	if((z>=0)&&(z<=9))
	{
		printf("%d->%c\n",z,(z+48));			
	}
	else
	printf("enter a valid input(0-9)\n");
}


	
/*fibonacci series*/

int fibonacci_series(int num)
{
	//int n1,n2,n3,i;
	int n1=0;
	int n2=1;
	int n3,i;
	printf("%d %d\t",n1,n2);
	for(i=2;i<=num;++i)
	{
		n3=n1+n2;
		printf("%d\t",n3);
		n1=n2;
		n2=n3;
	}	
}


	



void main(void)
{
	int num,x,y,z,n,opt,i,j,dec,a,b,c,n1,n2,n3,bin,bit,count=0,zero=0,one=0,res,rem,sum=0,temp;
	char sub_opt;
	while(1)
	{
		printf("\tMENU\n0.exit\n1.Bitwise operators\n2.Mathematical operations\n3.Swapping\n4.characters\n5.fibonacci series\n");
		printf("select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
		case 0:exit(0);
		case 1:printf("\tSELECT THE BIT-WISE OPERATIONS\n\ta.Replace 101 to 111\n\tb.count no.of zeros\n\tc.print the binary value\n\td.swap the bits from msb to lsb\n");
			{
				__fpurge(stdin);
				printf("enter the sub-opt:");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':__fpurge(stdin);
						printf("enter the hexavalue:");
						scanf("%x",&x);
						res=replace_one_zero_one(x);
						printf("%x\n",res);
						//printf("%d\n",count);
						break;

					case 'b':__fpurge(stdin);
						printf("enter the decimal value:");
						scanf("%d",&y);
						count_zeros(y);
						break;
					
					case 'c':__fpurge(stdin);
						printf("enter the decimal value:");
						scanf("%d",&z);
						binary_output(z);
						break;
					
					case 'd':
						__fpurge(stdin);printf("enter the hexavalue:");
						scanf("%x",&n);
						swap_bits(n);			
						break;
					default:printf("invalid opt\n");
				}
				break;
			}

		
		case 2:printf("select the option to perform mathematical operations\n\ta.sum of digits\n\tb.reverse of the number\n\tc.binary to decimal\n\td.decimal to binary\n");
			{
				printf("enter the sub_opt");
				__fpurge(stdin);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':__fpurge(stdin);
						printf("enter the decimal number:");
						scanf("%d",&num);
						res=sum_digits(num);
						printf("%d\n",res);
						break;

					case 'b':__fpurge(stdin);
						printf("enter the decimal number:");
						scanf("%d",&num);
						res=reverse_integer(num);
						printf("%d\n",res);
						break;

					case 'c':__fpurge(stdin);
						printf("enter the binary input\n");
						scanf("%d",&bin);
						res=binary_decimal(bin);
						if(res==-1)
							{
								printf("invalid input\n");
								break;
							}
						printf("%d",res);
						break;
				
					case 'd':__fpurge(stdin);
						printf("enter the decimal input\n");
						scanf("%d",&dec);
						res=decimal_binary(dec);
						if(res==-1)
							{
								printf("invalid input\n");
								break;
							}
						printf("%d",res);
						break;
					default:printf("invalid opt\n");
				}
				printf("--------------------------------------\n");
				break;
			}

		case 3:printf("select the options to perform swapping\na.using 2variables\nb.using 3variables\nc.swap using bitwise operator\n");
			{
				__fpurge(stdin);
				printf("enter the sub_opt");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':__fpurge(stdin);
						printf("enter the decimal inputs:");
						scanf("%d %d",&a,&b);
						swap_twovariables(a,b);
						break;
			
					case 'b':__fpurge(stdin);
						printf("enter the decimal inputs:");
						scanf("%d %d",&a,&b);
						swap_three(a,b);
						break;
				
					case 'c':__fpurge(stdin);
						printf("enter the decimal inputs:");
						scanf("%d %d",&x,&y);
						swap_bitwise(x,y);
						break;
					default:printf("invalid opt\n");
				}
				printf("--------------------------------------\n");
				break;
			}

		case 4:printf("select the options to perform ascii to integer and upper to lowercase\na.upper to lowercase\nb.lower to uppercase\nc.ascii to integer\nd.integer to ascii\n");
			{
				__fpurge(stdin);
				printf("enter the sub_opt:");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':__fpurge(stdin);
						printf("enter a character:");
						scanf("%c",&c);
						upper_lower(c);
						break;

					case 'b':__fpurge(stdin);
						printf("enter a character:");
						scanf("%c",&x);
						lower_upper(x);
						break;

					case 'c':__fpurge(stdin);
						printf("enter a ascii value:");
						scanf("%c",&y);
						ascii_integer(y);	
						break;

					case 'd':__fpurge(stdin);
						printf("enter a integer value:");
						scanf("%d",&z);
						integer_ascii(z);
						break;
				
					default:printf("invalid opt\n");
						break;
				}
				printf("--------------------------------------\n");
				break;
			}

		case 5:printf("select the options to perform fibonacci series\na.fibonacci series\n");
			{
				__fpurge(stdin);
				printf("enter the sub-option");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
				
					case 'a':__fpurge(stdin);
						printf("enter the number:");
						scanf("%d",&num);	
						fibonacci_series(num);
						break;

					default:printf("invalid opt\n");
				}
				break;
				printf("--------------------------------------\n");
			}
		default:printf("invalid opt");
		break;
		}
	}
}


					
						

		

			
						

		
		
						
						
				









	
			

		/*case 2:printf("enter the binary input\n");
			scanf("%d",&bin);
			res=binary_decimal(bin);
			if(res==-1)
			{
				printf("invalid input\n");
					break;
			}
			printf("%d",res);
				break;
		default:printf("invalid option\n");
		}
	}	
}





case 1:printf("\tSELECT THE BIT-WISE OPERATIONS\n\ta.Replace 101 to 111\n\tb.count no.of zeros\n\tc.print the binary value\n\td.swap the bits from msb to lsb\n");
			{
				__fpurge(stdin);
				printf("enter the sub-options:");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("enter the hexavalue:");
						scanf("%x",&x);
						for(i=0;i<=(31-3);i++)
						{
							if(((x&(0x7<<i))>>i)==(0x5))
							{
								bit=(bit|(0x7<<i));
								count++;
							}
						}
						printf("%x\n",bit);
						printf("count is %d",count);
						break;

					case 'b':printf("enter the decimal value:");
						scanf("%d",&x);
						zero=0;
						one=0;
						for(bit=31;bit>=0;bit--)
						{
							if((x&0x1<<bit)==0)
								zero++;
							else
								one++;
						}
						printf("zeros %d\n ones %d\n",zero,one);
						break;

					case 'c':printf("enter the decimal value:");
						scanf("%d",&x);
						for(bit=31;bit>=0;bit--)
						{
							if((x&0x1<<bit)==0)
								printf("0");
							else
								printf("1");
						}
						break;

					case 'd':printf("enter the hexavalue:");
						scanf("%x",&x);
						for(i=0,j=31;i<j;i++,j--)
							if((x&0x1<<i)^(x&0x1<<j))
							{
								x=(x&(~((0x1<<i)|(0x1<<j))))|((x&0x1<<i)<<(j-i))|((x&0x1<<j)>>(j-i));
							}
						printf("%x\n",x);
						break;
					//default:printf("invalid opt\n");
				}
				break;
			}
			case 2:printf("select the option to perform mathematical operations\n\ta.sum of digits\n\tb.reverse of the number\n\tc.decimal to binary\n\td.binary to decimal\n");
			{
				__fpurge(stdin);
				printf("enter the sub_opt");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("enter the decimal number:");
						scanf("%d",&num);
						temp=num;
						sum=0;
						while(temp>0)
						{
							rem=temp%10;
							temp=temp/10;
							sum=sum+rem;
						}
						printf("sum of the digits=%d\n",sum);
						break;

					case 'b':printf("enter the decimal number:");
						scanf("%d",&num);	
						temp=num;
						sum=0;
						while(temp>0)
						{
							rem=temp%10;
							temp=temp/10;
							sum=sum*10+rem;
						}	
						printf("reverse of the number %d\n",sum);
						break;
				
					case 'c':printf("enter the decimal number:");
						scanf("%d",&num);
						temp=num;
						sum=0;
						i=1;
						while(temp!=0)
						{
							rem=temp%2;
							temp=temp/2;
							sum=sum+i*rem;
							i=i*10;
						}
						printf(" binary value is%d\n",sum);
						break;
				
					case 'd':printf("enter the decimal number:");
						scanf("%d",&num);
						temp=num;
						sum=0;
						i=1;
						while(temp!=0)
						{
							rem=temp%10;
							temp=temp/10;
							sum=sum+i*rem;
							i=i*2;
						}
						printf(" decimal value is %d\n",sum);
						break;
					default:printf("invalid opt\n");
				}
				printf("--------------------------------------\n");
				break;
			}
			case 3:printf("select the options to perform swapping\na.using 2variables\nb.using 3variables\nc.swap using bitwise operator\n");
			{
				__fpurge(stdin);
				printf("enter the number");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("enter the decimal inputs:");
						scanf("%d %d",&a,&b);
						printf("before swapping %d %d\n",a,b);
						a=a+b;
						b=a-b;
						a=a-b;
						printf("after swapping %d %d",a,b);
						break;

					case 'b':printf("enter the decimal inputs:");
						scanf("%d %d",&a,&b);
						printf("before swapping %d %d\n",a,b);
						c=a;
						a=b;
						b=c;
						printf("after swapping %d %d",a,b);
						break;

					case 'c':printf("enter the decimal inputs:");
						scanf("%d %d",&a,&b);
						printf("before swapping %d %d\n",a,b);
						a=a^b;
						b=a^b;
						a=a^b;
						break;
						printf("after swapping %d %d",a,b);
					default:printf("invalid opt\n");
				}
				printf("--------------------------------------\n");
				break;
			}
			case 4:printf("select the options to perform ascii to integer and upper to lowercase\na.upper to lowercase\nb.lower to uppercase\nc.ascii to integer\nd.integer to ascii\n");
			{
				__fpurge(stdin);
				printf("enter the Option:");
				//scanf("%d",&x);
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
					case 'a':printf("enter a character:");
						__fpurge(stdin);
						scanf("%c",&c);
		  				if((c>=65)&&(c<=90))
						{
							printf("%c->%c\n",c,(c+32));			
						}
						else
							printf("enter a valid input\n");
						break;
					
					case 'b':printf("enter a character:");
						__fpurge(stdin);
						scanf("%c",&c);
						if((c>=97)&&(c<=122))
						{
							printf("%c->%c\n",c,(c-32));			
						}
						else
							printf("enter a valid input\n");
						break;
					
					case 'c':printf("enter a ascii value:");
						__fpurge(stdin);
						scanf("%c",&c);
						if((c>=48)&&(c<=57))
						{
							printf("%c->%d\n",c,(c-48));			
						}
						else
							printf("enter a valid input\n");
						break;

					case 'd':
					{
						printf("enter a integer value:");
						__fpurge(stdin);
						scanf("%d",&c);
						if((c>=0)&&(c<=9))
						{
							printf("%d->%c\n",c,(c+48));			
						}
						else
							printf("enter a valid input(0-9)\n");
						break;
					}
					default:printf("invalid opt\n");
						break;
				}
				printf("--------------------------------------\n");
				break;
			}
			case 5:printf("select the options to perform fibonacci series\n");
			{
				__fpurge(stdin);
				printf("enter the sub-option");
				scanf("%c",&sub_opt);
				switch(sub_opt)
				{
				
					case 'a':printf("enter the first two values:");
						scanf("%d%d",&n1,&n2);
						__fpurge(stdin);
						printf("enter the upto how times:");
						scanf("%d",&num);
						for(i=2;i<=num;++i)
						{
							n3=n1+n2;
							printf("%d\t",n3);
							n1=n2;
							n2=n3;
						}
						break;
					default:printf("invalid opt\n");
				}
				break;
				printf("--------------------------------------\n");
			}
			default:printf("invalid opt");
				break;
		}
	}
}*/




		

		
	
		



