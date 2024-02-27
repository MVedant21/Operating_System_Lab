#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/* Printing Parent and Child Process IDs: Write a program that calls fork and prints both the 
parent and child process IDs. */

int main(){
	pid_t pid;
	pid = fork();

	if (pid < 0){ // check if fork happened
		fprintf(stderr,"Fork failed\n");
		return 1;
	}
	else if (pid == 0){ // fork returns zero value for child
		printf("Child Process : PID = %d\n", getpid());
	}
	else{ // return child pid for the parent
		printf("Parent Process PID : %d , Child Process PID : %d\n", getpid(), pid);
	}
	return 0;
}
