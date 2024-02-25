#include<stdio.h>
#include<fcntl.h>
#include<sys/select.h>

/*Waiting for STDIN Using Select: Develop a program to wait for input from STDIN for 10 
seconds using select. Include proper print statements to verify data availability within the 
specified time.*/

int main(){
    fd_set fds;
    struct timeval t_val;
    int retval;

    t_val.tv_sec = 5;
    t_val.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(0, &fds);

    retval = select(1 ,&fds, NULL, NULL, &t_val);
    if (retval == -1)
    {
        perror("Error");
    }
    else if(retval){
        printf("Data is available now.\n");
    }
    else{
        printf("No data available in five seconds.\n");
    }
    return 0;
}
