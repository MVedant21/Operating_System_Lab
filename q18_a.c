#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

/*
. Record Locking Implementation: Write a program to perform record locking with the 
following implementations: 
a. Implement a write lock. 
b. Implement a read lock. 
Create three records in a file. Whenever you access a particular record, first lock it, then 
modify/access it to avoid race conditions
*/

int main() {
    int fd = open("18.txt", O_RDWR);
    int input;
    printf("Choose a record: 1 or 2 or 3: ");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK; // implementing Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(int); // start from the given offset
    lock.l_pid = getpid();

    printf("Inside Critical Section\n");
    fcntl(fd, F_SETLKW, &lock);
    int tokennum = 0;
    lseek(fd, tokennum, sizeof(int));
    tokennum++;

    printf("Token number is: %d\n", tokennum);
    lseek(fd, (input-1)*sizeof(int), SEEK_SET); // move the pointer at the end of the file
    write(fd, &tokennum, sizeof(int));
    printf("Critical section Ends\n");
    sleep(15); // waiting for fifteen seconds to simulate the critical section
    lock.l_type = F_UNLCK; // unlocking the process
    fcntl(fd, F_SETLK, &lock);
    printf("Unlock successful\n");
    close(fd);
}
