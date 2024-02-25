#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

/*Read-Only File Reading: Write a program to open a file in read-only mode, read line by line, 
and display each line as it is read. Close the file upon reaching the end of the file. */

int main() {
    // Open the file in read-only mode using open system call
    int fd = open("newfile", O_RDONLY);

    // Check if the file is opened successfully
    if (fd == -1) {
        perror("Error opening the file");
        return 1; // Exit with an error code
    }

    // Read and display each line in the file using read and write system calls
    char buf[1024];
    int size;
    while ((size = read(fd, buf, sizeof(buf))) > 0) {
        write(1, buf, size);
    }

    // Check for read errors
    if (size == -1) {
        perror("Error reading from the file");
        close(fd);
        return 1; // Exit with an error code
    }


    // Close the file using close system call
    close(fd);

    return 0; // Exit successfully
}

