#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

/*Creating a Zombie State: Write a program to create a zombie state in the running program.*/

int main(){
	int res = fork();
	if (res > 0){
		sleep(100);
	}
	else{
		exit(1);
	}
	
	return 0;
}
