#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/* Online Ticket Reservation Simulation: Develop a program to simulate online ticket 
reservation with the implementation of a write lock. Write one program to open a file, store 
a ticket number, and exit. Write a separate program to open the file, implement a write 
lock, read the ticket number, increment the number, print the new ticket number, and then 
close the file.*/

int main(int argc, char *argv[]){
	int fd;
	write(1,"Before lock\n",sizeof("Before lock\n"));
	fd = open("ticket.txt",O_RDWR);
	int num;

	struct flock lock;
	lock.l_len = 0;
	lock.l_start = 0;
	lock.l_whence = SEEK_SET;
	lock.l_type = F_WRLCK;
	
	fcntl(fd, F_SETLKW, &lock);
	lseek(fd, 0, SEEK_SET);
	read(fd, &num, sizeof(int));
	printf("Number of tickets:%d\n",num);
	printf("Incrementing the number\n");
	num++;

	lseek(fd,0,SEEK_SET);
	write(fd, &num, sizeof(int));

	char ch;
	read(0, &ch, sizeof(char));

        write(1, "Incremented. Now unlocking\n", sizeof("Incremented. Now unlocking\n"));

        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLKW, &lock);
        printf("Unlocked\n");
        close(fd);

	return 0;
}
