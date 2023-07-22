// Program to create n child processes from a single parent process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		if (fork() == 0) {
			printf("PID : %d, Parent PID : %d\n", getpid(), getppid());
			exit(0);
		}
	}
}