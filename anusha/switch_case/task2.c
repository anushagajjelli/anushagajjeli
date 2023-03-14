#include<stdio.h>
main()
{
	int opt,x,num,bit=0,i,j,zero=0,one=0,sum=0,count=0,rem,temp,a,b,c,n1,n2,n3;
	char sub_opt;
	printf("\tOPTIONS\n\t0.exit\n\t1.Bitwise operations\n\t2.Mathematical operators\n\t3.swap the variable\n\t4.Ascii to integer\n\t5.Fibonacci series\n\tEnter the Option:");
	scanf("%d",&opt);
	//printf("enter the number\n");
	//scanf("%d",&x);
	while(1)
	{
		switch(opt)
		{
			case 0:exit(0);
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
}




		

		
	
		






	
