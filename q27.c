#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>

/*Getting Maximum and Minimum Real-Time Priority: Develop a program to retrieve the 
maximum and minimum real-time priority.*/

int main(){
	printf("Max priority for real-time round-robin: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Min priority for real-time round-robin: %d\n", sched_get_priority_min(SCHED_RR));
	return 0;
}
