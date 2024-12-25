// Write a program that opens a file (with the open() system call) 
// and then calls fork() to create a new process. Can both the child 
// and parent access the file descriptor returned by open()? What 
// happens when they are writing to the file concurrently, i.e., 
// at the same time?
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int file = open("file.txt", O_CREAT | O_RDWR, 0644);
    if(file < 0){
        printf("File open failed\n");
        exit(1);
    }
    int rc = fork();
    if(rc < 0){
        printf("Fork failed\n");
        exit(1);
    }
    else if(rc == 0){
        char *child = "Child process writing to file\n";
        write(file, child, strlen(child));
    }
    else{
        char *parent = "Parent process writing to file\n";
        write(file, parent, strlen(parent));
    }
    close(file);
    return 0;
}