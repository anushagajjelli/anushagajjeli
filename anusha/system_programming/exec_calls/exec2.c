//wap to verify the execv and execvp calls

#include<stdio.h>
#include<unistd.h>
void main()
{
	//char *const argv[]={"ps","-ef",NULL};
	//execvp(argv[0],argv);
	 
	char *const argv[]={"/bin/ps","ps","-ef",NULL};//for execv with providing the path
	execv(argv[0],&argv[1]);

}
