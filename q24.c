#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

/*Creating and Waiting for Child Processes: Write a program to create three child processes. 
The parent process should wait for a specific child process using the waitpid system call. */

void function(){
	int status;
	pid_t pid[3];

	for (int i=0;i<3;i++){
		pid[i] = fork();
		if (pid[i] == 0){
			printf("Child %d\n",getpid());
			if (i == 2){
				sleep(10);	
			}
			else{
				sleep(2);
			}
			exit(100 + i);
		}
	}
	pid_t cpid_to_wait = waitpid(pid[2],&status,0);
	printf("Child %d terminated with status : %d\n", cpid_to_wait, WEXITSTATUS(status));
}

int main(){
	function();
	return 0;
}
	
