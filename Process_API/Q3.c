#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if(pid==0){
        // child process created
        printf("hello\n");
    } else {
        // wait(NULL);
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}

