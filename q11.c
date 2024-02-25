#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

/*File Descriptor Duplication and Appending: Write a program to open a file, duplicate the 
file descriptor, append the file with both descriptors, and verify whether the file is updated 
correctly.  
a. Use dup  
b. Use dup2  
c. Use fcntl */

int main(int argc, char *argv[]){
	int fd;
	fd = open(argv[1], O_WRONLY|O_APPEND);
	if (argc != 2){
		fprintf(stderr,"Usage: %s filename\n",argv[0]);
		return 1;
	}
	write(fd, "append using the orignal fd \n", 28);
	
	// part(a)
	int fd1 = dup(fd);
	write(fd1, "append using fd1 \n", sizeof("From New Fd\n"));

	//part(b)
	int fd2;
	dup2(fd,fd2);
	write(fd2, "append using fd1 \n", sizeof("From New Fd\n"));

	//part(c)
	int fd3 = fcntl(fd,F_DUPFD);
	write(fd3, "append using fd1 \n", sizeof("From New Fd\n"));
	return 0;
}
