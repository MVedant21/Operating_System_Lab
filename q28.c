#include<unistd.h>
#include<sys/resource.h>

int main(){

    int priority = getpriority(PRIO_PROCESS, getpid()); // getting the initial priority of the process
    if(priority == -1){
        perror("getpriority");
        return -1;
    }
    printf("The priority of the current process is %d\n", priority);
    printf("Changing the priority of the current process by 5\n");

    nice(5); // changing the priority of the process by five
    priority = getpriority(PRIO_PROCESS, getpid());
    if(priority == -1){
        perror("getpriority");
        return -1;
    }
    printf("The priority of the current process after increment is %d\n", priority); // printing the updated priority
    

}
	return 0;
}
