#include<stdio.h>
int main()
{
int n1=0;
int n2=1;
int n3,i,n;
printf("enter a number:");
scanf("%d",&n);
printf("\n %d %d",n1,n2);
for(i=2; i<=n; ++i){
n3=n1+n2;
printf("%d",n3);
n1=n2;
n2=n3;
}
return 0;
}
