#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/*Running a Script at a Specific Time with a Daemon Process: Create a program to execute a 
task at a specific time using a Daemon process. */

int main(){
    pid_t pid = fork();

    if(pid == 0){
        // Child process
        setsid();
        chdir("/");
        umask(0);
        int fd = open("daemon_process", O_RDWR|O_CREAT, 0644);
        while(1){
            sleep(5);
            printf("It's a daemon process\n");
        }
        close(fd);
    }
    else{
        // Parent process
        exit(0);
    }
    return 0;
}
