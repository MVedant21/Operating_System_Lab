#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

/*File Copying: Develop a program to copy the contents of file1 into file2, emulating the 
behavior of the $cp file1 file2 command. */

int main(){
	int fd;
	char buf[1000];
	fd = open("newfile",O_RDONLY);
	int size = read(fd,buf,sizeof(buf)); // reading from the file newfile
	close(fd); // closing the file
	fd = open("newfile1",O_CREAT|O_WRONLY); // opening the file newfile1 and write the content of newfile into it via buffer
	write(fd,buf,size);
	close(fd);
	return 0;
}
