#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>

/*Getting and Modifying Scheduling Policy: Write a program to obtain the scheduling policy 
and modify it (e.g., SCHED_FIFO, SCHED_RR). */

int main(){
	printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	printf("Enter a choice number to change policy:\n");
	printf("1. SCHED_RR\n");
	printf("2. SCHED_FIFO\n");
	
	struct sched_param sp;
	sp.sched_priority = 50;

	int choice = 0;
	scanf("%d",&choice);
	if (choice != 1 && choice != 2){
		printf("Invalid choice : %d",choice);
	}
	if (choice == 1){
		sched_setscheduler(getpid(), SCHED_RR, &sp);
		printf("Scheduling policy changed to SCHED_RR\n");
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	else if (choice == 2){
		sched_setscheduler(getpid(), SCHED_FIFO, &sp);
		printf("Scheduling policy changed to SCHED_FIFO\n");
		printf("The current scheduling policy is: %d\n", sched_getscheduler(getpid()));
	}
	return 0;
}

