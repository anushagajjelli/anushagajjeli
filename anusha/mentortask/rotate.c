void rotate_elements(int* arr,int n)
{
	int i,j,temp,MAX;
	for(i=0;i<n;i++)
	{
		temp=arr[0];
		for(j=0;j<MAX-1;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[j]=temp;
	}
	for(i=0;i<MAX;i++)
	printf("%d",arr[i]);
}
	
