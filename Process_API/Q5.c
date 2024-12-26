#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        printf("Fork failed\n");
    }
    else if(pid==0){
        // wait(NULL);
        printf("Child process\n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
    }
    else{
        wait(NULL);
        printf("Parent process\n");
        printf("PID: %d\n", getpid());
        printf("PPID: %d\n", getppid());
    }
    return 0;
}