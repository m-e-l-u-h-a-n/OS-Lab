#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum State {
	EATING,
	THINKING,
	HUNGRY
};

int num = 5;
int *states;
sem_t *forks;
sem_t mutex;

char getStateName(int state){
	switch(state){
		case EATING: return 'E'; break;
		case THINKING: return 'T'; break;
		case HUNGRY: return 'H'; break;
	}
}

void take_forks(int n) {
	int left = n;
	int right = (n + 1) % num;

	sem_wait(&mutex);

	states[n] = HUNGRY;	
	sem_wait(&forks[left]);
	sem_wait(&forks[right]);
	states[n] = EATING;

	sem_post(&mutex);
}

void put_forks(int n) {
	int left = n;
	int right = (n + 1) % num;

	sem_post(&forks[left]);
	sem_post(&forks[right]);

	states[n] = THINKING;
}

void* philosopher (void* arg)
{
	int n =*((int *)arg);
	while(1)
	{ 		
		sleep(rand()%10+1);
		take_forks(n);
		sleep(rand()%10+1);
		put_forks(n);
	}	
}

int main() {
	states = malloc(sizeof(int)*num);	
	
	for (int i = 0; i < num; i++)
		states[i] = THINKING;
	
	forks = malloc(sizeof(sem_t)*num);
	
	sem_init(&mutex, 0, 1);
	pthread_t philosophers[num];
	
	for(int i = 0; i < num; i++)
	{  		
		sem_init(&forks[i], 0, 1);
		int *arg= malloc (sizeof(int));
		*arg = i;
		pthread_create(&philosophers[i], NULL, philosopher, (void *)arg);
	}

	while(1)
	{
		sleep(1);
		for (int j = 0; j < num; j++)
		{
			char state = getStateName(states[j]);
			printf(" %c - ", state);
		}
		printf("\n");
	}
	pthread_exit(0); 
}