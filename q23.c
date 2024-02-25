#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

/* Creating an Orphan Process: Develop a program to create an orphan process. */

int main(){
        int res = fork();
        if (res > 0){
                exit(1);
        }
        else{
		printf("Pid of child : %d , Pid of parent : %d\n", getpid(), getppid());
                sleep(5);
		printf("Pid of child : %d , Pid of parent : %d\n", getpid(), getppid());
        }

        return 0;
}
