#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

#define MSGSIZE 100
#define N 2
  
int main() 
{ 
    int p[2], i; 
  	char s[100];
    if (pipe(p) < 0) 
        exit(1); 

    printf("Enter the messages to write:\n");
    for (int i = 0; i < N; i++) {
    	scanf("%s", s);
    	write(p[1], s, MSGSIZE);
    }

    printf("\nWritten messages:\n");
    for (i = 0; i < N; i++) { 
        read(p[0], s, MSGSIZE); 
        printf("%s\n", s); 
    } 
    return 0; 
}