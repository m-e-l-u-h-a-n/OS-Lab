// Program to create a child process from parent process and print their PIDs

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Inside Child Process:\n");
        printf("PID = %d\n", getpid());
    }
    else if (pid > 0) {
        wait(0);
        printf("Inside Parent Process:\n");
        printf("PID = %d\n", getpid());
    }
    else {
        printf("Fork failed!");
    }
}