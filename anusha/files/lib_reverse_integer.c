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
