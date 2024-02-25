#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

/* Online Ticket Reservation Simulation: Develop a program to simulate online ticket 
reservation with the implementation of a write lock. Write one program to open a file, store 
a ticket number, and exit. Write a separate program to open the file, implement a write 
lock, read the ticket number, increment the number, print the new ticket number, and then 
close the file.*/

int main(){
	int n;
	printf("Enter a number\n");
	scanf("%d",&n);

	int fd;
	fd = open("ticket.txt", O_WRONLY | O_CREAT, 0744);
	write(fd, &n, sizeof(int));
	printf("Write successful\n");
	
	close(fd);
	return 0;
}
