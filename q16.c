#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

/*Mandatory Locking Implementation: Write a program to perform mandatory locking with 
the following implementations:  
a. Implement a write lock.  
b. Implement a read lock.*/

int main(int argc, char *argv[]){
	int fd;
	fd = open(argv[1],O_RDWR);
	int option;
	printf("Type 1 for implementing a write lock OR Type 2 for implementing a read lock\n");
	scanf("%d",&option);

	if (option == 1){
		char name[100];
		printf("Enter name of the file:\n");
		scanf("%s",name);

		struct flock lock;
		lock.l_start = 0;
		lock.l_len = 0;
		lock.l_whence = SEEK_SET;
		lock.l_type = F_RDLCK;
		int fd1;
		fd1 = open(name, O_RDONLY, 0744);

		int res = fcntl(fd1, F_SETLKW, &lock);
		if (res < 0){
			printf("Lock Unsuccessful\n");
			return 0;
		}
		printf("Locked\n");

		printf("Unlocking\n");
		lock.l_type = F_UNLCK;
		res = fcntl(fd1, F_SETLKW, &lock);
		if (res < 0){
			printf("Unlock Unsucessful\n");
			return 0;
		}
		printf("Unlocked\n");
		close(fd);
	}
	else if (option == 2){
		char name[100];
		printf("Enter name of the file:");
		scanf("%s",name);

		struct flock lock;
		lock.l_start = 0;
		lock.l_len = 0;
		lock.l_whence = SEEK_SET;
		lock.l_type = F_WRLCK;

		int fd1 = open(name, O_WRONLY, 0744);
		int res = fcntl(fd1, F_SETLKW, &lock);
		if (res < 0){
			printf("Lock Unsuccessful\n");
			return 0;
		}
		printf("Locked\n");
		printf("Unlocking\n");
                lock.l_type = F_UNLCK;
                res = fcntl(fd1, F_SETLKW, &lock);
                if (res < 0){
                        printf("Unlock Unsucessful\n");
                        return 0;
                }
                printf("Unlocked\n");
                close(fd);
	}
	else{
		printf("Invalid choice");
	}
	return 0;
}
