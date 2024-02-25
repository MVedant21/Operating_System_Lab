#include<stdio.h>
#include<unistd.h>

/* Executing ls -Rl Using Various exec System Calls: Write a program to execute ls -Rl using 
the following system calls:  
a. execl  
b. execlp  
c. execle  
d. execv  
e. execvp*/

int main(){
	printf("Execute ls -Rl using execl\n");
	execl("/bin/ls","/bin/ls","-R","-l",NULL);
	return 0;
}
