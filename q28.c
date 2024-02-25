#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>

/* Determining and Modifying Program Priority: Find out the priority of your running program 
and modify it using the nice command.*/

int main(){
	int priority = getpriority(PRIO_PROCESS, 0);

	if (priority == -1){
		printf("Error getting the priority");
		return 1;
	}
	printf("Current priority : %d\n",priority);

	int pid = getpid();
	renice -n priority pid; 
	priority = getpriority(PRIO_PROCESS,0);

	printf("Updated priority : %d\n",priority);
	return 0;
}
