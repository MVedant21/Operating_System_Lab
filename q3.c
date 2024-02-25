#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

extern int errno;

/*File Creation and Descriptor Printing: Write a program that creates a file and prints its file 
descriptor value using the creat() system call.*/

int main(){
	int fd = open("tp.txt", O_RDWR | O_CREAT); // opening the file with the required conditions
	if (fd == -1){
		printf("Error no. %d\n",errno);
		perror("Program");
	}
	printf("fd = %d\n", fd);
	return 0;
}
