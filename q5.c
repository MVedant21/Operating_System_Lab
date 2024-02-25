#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

/*Continuous File Creation: Create a program that generates five new files in an infinite loop. 
Execute the program in the background and inspect the file descriptor table at /proc/pid/fd.*/

int main(){	
	int fd1 = open("tp1.txt",O_CREAT);
	int fd2 = open("tp2.txt",O_CREAT);
	int fd3 = open("tp3.txt",O_CREAT);
	int fd4 = open("tp4.txt",O_CREAT);
	int fd5 = open("tp5.txt",O_CREAT);
	while(1){
	}
	return 0;
}
