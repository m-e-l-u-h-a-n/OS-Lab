#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
  
int main() 
{ 
    key_t key = ftok("file", 1234);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *s = (char*) shmat(shmid,0,0);
    printf("Data read from memory (shmid=%d, key=%d): %s\n", shmid, key, s);
    shmdt(s);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}