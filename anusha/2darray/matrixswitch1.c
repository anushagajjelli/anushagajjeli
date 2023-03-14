//wap to perform matrix operations satatically using switch case

#include<stdio.h>
#include<stdlib.h>
#define r 3
#define c 3
#define r1 3
#define c1 3
void addition(int(*mat1)[3],int(*mat2)[3],int(*res)[3]);
void multiplication(int(*mat1)[3],int(*mat2)[3],int(*res)[3]);
void transpose(int(*mat1)[3],int(*mat2)[3]);
void lowermat(int(*mat1)[3]);
void uppermat(int(*mat1)[3]);
void main()
{
	int i,j,opt;
	int mat1[r][c];
	int mat2[r1][c1];
	int res[r][c];
	while(1)
	{
		printf("\nMenu\n0.exit\n1.Addition\n2.Multiplication\n3.Transpose\n4.Lowertriangle matrix\n5.Uppertriangle matrix\n");
		printf("Select the option\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			
			case 1:printf("PERFORM ADDITION MATIX\n");
				if((r==r1)&&(c==c1))
				{
					addition(mat1,mat2,res);
				}
				else
					printf("addition is not possible\n");
				break;
				
			case 2:printf("PERFORM MULTIPLICATION MATRIX\n");
				if(c==r1)
				{
					multiplication(mat1,mat2,res);
				}
				else
					printf("multiplication process is not possible when r!=c1");
				break;
	
	
			case 3:printf("PERFORM TRANSPOSE MATRIX\n");
				if((r==r1)&&(c==c1))
				{
					transpose(mat1,mat2);
				}
				else
					printf("transpose matrix is not possible\n");
				break;			
				
			case 4:printf("PERFORM LOWERTRIANGLE MATRIX\n");
				if(r==c)
				{
					lowermat(mat1);
				}
				else
					printf("lowertriangle is not possible with invalid r and c\n");
				break;
				
			case 5:printf("PERFORM UPPERTRIANGLE MATRIX\n");
				if(r==c)
				{
					uppermat(mat1);
				}
				else
					printf("uppertriangle is not possible with invalid r and c\n");
				break;
				
			default:printf("Invalid option:");
		}
		printf("\n......................................\n");
	}
	
}

void addition(int(*mat1)[3],int(*mat2)[3],int(*res)[3])
{
	int i,j;
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter the matrix mat2(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat2[i][j]);
		}
	}
	printf("Matrix-1\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
	}
	printf("Matrix-2\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat2[i][j]);
		}
	}
	printf("Addition of matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			res[i][j]=mat1[i][j]+mat2[i][j];
			printf("%d \t",res[i][j]);
		}
	}
}
	
	

void multiplication(int(*mat1)[3],int(*mat2)[3],int(*res)[3])
{
	int i,j,k;
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat1[i][j]);
		}
	}
	
	printf("Enter the matrix mat2(%d*%d)\n",r1,c1);
	for(i=0;i<r1;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat2[i][j]);
		}
	}
	
	printf("First matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
	}
	
	printf("Second matrix\n");
	for(i=0;i<r1;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			printf("%d \t",mat2[i][j]);
		}
	}
	
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			res[i][j]=0;
			for(k=0;k<c;k++)
				res[i][j]=res[i][j]+mat1[i][k]*mat2[k][j];
		}
	}
	
	printf("Multiplication of the matrix\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c1;j++)
		{
			printf("%d  \t",res[i][j]);
		}
		printf("\n");
	}
}
	
	
void transpose(int(*mat1)[3],int(*mat2)[3])
{
	int i,j;
	printf("Enter the matrix mat1(%d*%d)\n",r,c);
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Before Transpose:\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			mat2[i][j]=mat1[j][i];
		}
	}
	printf("After Transpose\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mat2[i][j]);
		}
		printf("\n");
	}
}



void lowermat(int(*mat1)[3])
{
	int i,j;
	int mat[r][c];
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Before change\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
	}
	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(((i==0)&&(j==1))||((i==0)&&(j==2))||((i==1)&&(j==2)))
				{
					mat[i][j]=mat[i][j]-mat[i][j];//now upper elements becomes zero by subtracting
				}
				else
					mat[i][j];
			}
		}
	}
	printf("After changing the lower matrix triangle\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
		printf("\n");
	}
}


void uppermat(int(*mat1)[3])
{
	int i,j;
	int mat[r][c];
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("Entered elements are [%d][%d]:",i,j);
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Before change\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
	}
	if(r==c)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(((i==1)&&(j==0))||((i==2)&&(j==0))||((i==2)&&(j==1)))
				{
					mat[i][j]=mat[i][j]-mat[i][j];//now lower elements becomes zero by subtracting
				}
				else
					mat[i][j];
			}
		}
	}
	printf("After changing the upper matrix triangle\n");
	for(i=0;i<r;i++,printf("\n"))
	{
		for(j=0;j<c;j++)
		{
			printf("%d \t",mat[i][j]);
		}
		printf("\n");
	}
}
