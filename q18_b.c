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
    printf("Choose a record: 1 or 2 or 3:");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_RDLCK; // setting the lock to Read mode
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(int); // setting the offset value
    lock.l_len = sizeof(int);
    lock.l_pid = getpid();

    printf("Inside critical section\n");
    fcntl(fd, F_SETLKW, &lock); // implementing the lock using the fcntl function
    int tokennum = 0;
    lseek(fd, (input - 1) * sizeof(int), SEEK_SET); // move the pointer before the user input
    read(fd, &tokennum, sizeof(int));
    tokennum++;

    printf("Token number is %d\n", tokennum);
    lseek(fd, (input - 1) * sizeof(int), SEEK_SET);
    write(fd, &tokennum, sizeof(int));
    printf("Critical section ends\n");
    sleep(15); // sleep for fifteen seconds to simulate the critical section 
    lock.l_type = F_UNLCK; // unlock the process
    fcntl(fd, F_SETLK, &lock);
    printf("Unlock successful\n");
    close(fd);
}
