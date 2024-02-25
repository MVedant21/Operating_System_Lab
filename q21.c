#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* File Writing by Parent and Child Processes: Develop a program that opens a file, calls fork, 
and allows both the child and parent processes to write to the file. Examine the output of 
the file.*/

int main(int argc, char *argv[]){
	int fd = open(argv[1], O_WRONLY);
	int res;
	res =  fork();

	if (res < 0){
		fprintf(stderr, "Fork unsuccessful");
	}
	else if (res == 0){
		printf("Child is writing\n");
		write(fd,"Child is writing",16);
	}
	else{
		printf("Parent is writing\n");
		write(fd, "Parent is writing", 17);
	}
	return 0;
}
