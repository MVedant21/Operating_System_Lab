#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
	// link function
	int l = link(argv[1],argv[2]);
	// argv[1] is existing file name
	// argv[2] is link file name
	if (l == 0){
		printf("Hard Link created successfully");
	}
	return 0;
}
