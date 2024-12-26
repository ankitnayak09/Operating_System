// Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the pipe() system call.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int pipefd[2];
    pid_t pid1,pid2;

    // Create pipe
    if(pipe(pipefd)==-1){
        printf("Pipe failed\n");
        return 1;
    }

    // Create the first child process
    pid1 = fork();
    if(pid1 < 0){
        perror("fork failed");
        return 1;
    } else if(pid1 == 0){
        close(pipefd[0]); // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe write end
        close(pipefd[1]); // Close the original write end

        // Execute a command that writes to stdout
        execlp("ls", "ls", NULL);
        perror("execlp failed");
        return 1;
    }
    // Create the second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    } else if (pid2 == 0) {
        // Second child process
        close(pipefd[1]); // Close unused write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the pipe read end
        close(pipefd[0]); // Close the original read end

        // Execute a command that reads from stdin
        execlp("wc", "wc", "-l", NULL);
        perror("execlp failed");
        return 1;
    }

     // Parent process
    close(pipefd[0]); // Close unused read end
    close(pipefd[1]); // Close unused write end

    // Wait for both child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}
