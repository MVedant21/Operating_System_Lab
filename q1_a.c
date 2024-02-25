#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/*Creating Different File Types: Utilize both shell commands and system calls to create the 
following types of files: 
a. soft link (using the symlink system call) 
b. hard link (using the link system call) 
c. FIFO (using either the mkfifo Library Function or the mknod system call)*/

int main(int argc, char* argv[]){
	int sl = symlink(argv[1],argv[2]); // Symlink function
	// argv[1] is existing file name
	// argv[2] is soft link file name
	if (sl == 0){
		printf("SOFTLINK created successfully");
	}
	return 0;
}
