#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

/*Opening Existing File: Write a program to open an existing file in read-write mode. 
Experiment with the O_EXCL flag.*/

int main(){
	int fd = open("tp.txt",O_CREAT|O_EXCL,0744); // create a file if doesn't exist or open the mentioned file if aldready created
	perror("fd");
	printf("fd = %d\n", fd);
	return 0;
}
