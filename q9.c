#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

/*File Information Extraction: Create a program to print various details about a given file, 
including: 
a. Inode 
b. Number of hard links 
c. UID 
d. GID 
e. Size 
f. Block size 
g. Number of blocks 
h. Time of last access 
i. Time of last modification 
j. Time of last change */

int main(int argc, char* argv[]){
	struct stat temp;

	if(argc!=2){
       		fprintf(stderr,"Usage: %s filename\n",argv[0]);
       		return 1;
    	}
    	stat(argv[1],&temp); // gets status information regarding the mentioned file
    	printf("inode number : %ld\n",temp.st_ino);
    	printf("number of hardlinks : %ld\n ",temp.st_nlink);
    	printf("uid : %d\n",temp.st_uid);
    	printf("gid : %d\n",temp.st_gid);
    	printf("size : %ld\n",temp.st_size);
    	printf("blocksize : %ld\n",temp.st_blksize);
    	printf("number of blocks : %ld\n",temp.st_blocks);
    	printf("last access : %s",ctime(&temp.st_atime));
    	printf("time of last modification : %s",ctime(&temp.st_mtime));
    	printf("time of last change : %s",ctime(&temp.st_ctime));
    	return 0 ;
}
