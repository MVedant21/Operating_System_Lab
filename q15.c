#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

extern char **environ; // creating an external evironmental variable

/*Displaying User Environmental Variables: Create a program to display the environmental 
variables of the user, utilizing the environ variable. */

int main(){
	for (char **env = environ;*env != NULL;env++){ // loop to iterate through the environment variables 
		printf("%s\n",*env);
	}
	return 0;
}
