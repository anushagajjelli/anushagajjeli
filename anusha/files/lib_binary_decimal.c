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
