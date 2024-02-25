#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

/* Executing an Executable Program:  
a. Execute a program using the exec system call.  
b. Pass input to an executable program (e.g., execute an executable as $./a.out name).*/

int main(int argc, char *argv[]){
	printf("Following is present in the file:-\n");
	execv(".helloworld",argv);
	return 0;
}
