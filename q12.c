#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

/* Determining Opening Mode of a File: Create a program to find out the opening mode of a 
file using the fcntl system call. */

int main(){
	int fd = open("file2.txt", O_RDONLY);
	int res = fcntl(fd, F_GETFL);
	printf("fcntl returns : %d\n",res);

	if (res < 0){
		printf("Error.. \n");
	}
	else if((res & O_ACCMODE) == O_RDONLY){
		printf("File opened in O_RDONLY mode\n");
	}
	else if((res & O_ACCMODE) == O_RDWR){
		printf("File opened in O_RDWR mode\n");
	}
	else if((res & O_ACCMODE) == O_WRONLY){
		printf("File opened in O_WRONLY mode");
	}
	else{
		printf("File opened in other mode than the above mentioned\n");
	}
	return 0;
}
