// Write a program that calls fork(). 
// Before calling fork(), have the main process access
// a variable (e.g., x) and set its value to something
// (e.g., 100). What value is the variable in the child 
// process? What happens to the variable when both the child
// and parent change the value of x?
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int x = 100;
    pid_t pid = fork();
    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: x = %d\n", x);
        x = 200;
        printf("Child process: x changed to %d\n", x);
    } else {
        // Parent process
        printf("Parent process: x = %d\n", x);
        x = 300;
        printf("Parent process: x changed to %d\n", x);
    }

    return 0;
}