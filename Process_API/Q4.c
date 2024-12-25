#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Using execl:\n");
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");

        printf("Using execle:\n");
        char *envp[] = { NULL };
        execle("/bin/ls", "ls", NULL, envp);
        perror("execle failed");

        printf("Using execlp:\n");
        execlp("ls", "ls", NULL);
        perror("execlp failed");

        printf("Using execv:\n");
        char *args[] = { "ls", NULL };
        execv("/bin/ls", args);
        perror("execv failed");

        printf("Using execvp:\n");
        execvp("ls", args);
        perror("execvp failed");

        exit(1);
    } else {
        // Parent process
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}