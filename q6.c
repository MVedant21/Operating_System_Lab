#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*Input and Output Using System Calls: Craft a program to take input from STDIN and display 
it on STDOUT using only read/write system calls. */

int main(void){
	char buf[1000];
	int size = read(0,buf,sizeof(buf));
	write(1,buf,size);
}
