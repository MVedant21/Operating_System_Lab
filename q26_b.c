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
	printf("Executes ls -Rl using execlp\n");
	execlp("ls", "ls","-R", "-l", NULL);
	return(0);
}
