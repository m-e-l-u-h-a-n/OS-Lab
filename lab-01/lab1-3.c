// Program to call fork() 3 times and then print "Hello". This will print Hello 2^3 = 8 times.
// 11 System Calls are generated here (maybe...), 8 for fork, 1 for printf, 1 while starting and 1 while returning

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	fork();
	fork();
	fork();
	printf("Hello\n");
}