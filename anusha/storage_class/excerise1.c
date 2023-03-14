/*main()
{
	int x=10;
	if(x<=10)
	{
		main();
		printf("%d\n",x);
		x++;
	}
}*/

main()
{
	increment();
	increment();
	increment();
}
void increment()
{
	static int x=10;
	x++;
	printf("%d\n",x);
}
	
