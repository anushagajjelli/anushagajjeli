#include<stdio.h>
#include<string.h>
void main()
{
	char arr[10]="anusha.";
	printf("%s\n",arr);
	memset(arr+2,'s',2*sizeof(char));
	//bzero(arr+2,sizeof(char));
	printf("%s\n",arr);
}
//MEMSET: is used to fill the block of memory with particular value which is of int type arrgument1: base adress from where we wanted to replace.
//argument2: the value or particular charecter by which we would like to replace
//argument3:size of the block should be replaced.
//note: if we provide the string which is not a character then it will through a warning and considr the last character from the string because the data which we have provided is stored in the little indian formate where only late character is considere to replace the block of value.
//BZERO: is used to fill the block of memory with null characters .
//where it taker two aguments 1. base arddress of the block of memory.2. size of the block of memory.
