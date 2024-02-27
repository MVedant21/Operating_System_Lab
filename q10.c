#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/*File Write and Seek: Implement a program to open a file in read-write mode, write 10 
bytes, move the file pointer by 10 bytes using lseek, and then write another 10 bytes.  
a. Check the return value of lseek.  
b. Open the file with od command and examine the empty spaces between the data.*/

int main(int argc, char *argv[]){
	int fd;
	fd = open(argv[1], O_RDWR | O_CREAT, 0666);
	if (argc != 2){
		fprintf(stderr, "Usage: %s filename\n",argv[0]);
		return 1;
	}
	if (fd == -1){
		perror("open");
		return -1;
	}
	
	int bytes_written = write(fd, "0123456789", 10); // write ten bytes of data into the file given by the user
	if (bytes_written == -1){
		perror("write");
		return -1;
	}
	printf("Wrote %d bytes ot the file\n", bytes_written);

	int offset = lseek(fd, 10, SEEK_CUR); // shift the pointer by ten bytes 
	if (offset == -1 ){
		perror("lseek");
		return -1;
	}
	printf("Moved the filepointer by %d bytes\n",bytes_written);

	bytes_written = write(fd, "abcdefghij", 10); // write ten bytes again after changing the pointer
	if (bytes_written == -1){
		perror("write");
		return -1;
	}
	printf("Wrote %d bytes to file\n", bytes_written);
	
	if (close(fd) == -1){
		perror("close");
		return -1;
	}
	char command[1000];
	sprintf(command,"od -c %s",argv[1]);
	system(command);
	
	return 0;
}
