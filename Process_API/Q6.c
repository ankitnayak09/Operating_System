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
        int status;
        pid_t child_pid = waitpid(pid,&status,0)
        if (child_pid > 0) {
            printf("Parent process\n");
            printf("PID: %d\n", getpid());
            printf("PPID: %d\n", getppid());
            printf("Child process with PID %d terminated\n", child_pid);
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;
}