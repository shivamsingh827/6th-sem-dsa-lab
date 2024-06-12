#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <semaphore.h> 

#define N 5 
#define LEFT (pno + 4) % N
#define RIGHT (pno + 1) % N

enum {THINKING, HUNGRY, EATING} state[N]; 

sem_t self[N];
sem_t mutex;  
int chops = N; 

void test(int pno) 
{ 
    if (state[pno] == HUNGRY && chops>=2) 
    { 
        chops-=2;
        state[pno] = EATING; 
        printf("Philosopher %d TAKES 2 chopsticks for EATING\t %d chopsticks left\n",  pno + 1, chops); 
        sem_post(&self[pno]); 
    } 
} 

void pickup(int pno) 
{ 
    sem_wait(&mutex); 
    state[pno] = HUNGRY; 
    printf("Philosopher %d is HUNGRY\n", pno + 1);
    test(pno); 
    sem_post(&mutex); 
    if(state[pno]!=EATING)
	    sem_wait(&self[pno]);
} 

void putdown(int pno) 
{ 
    sem_wait(&mutex); 
    chops+=2;
    state[pno] = THINKING; 
    printf("Philosopher %d PUTS DOWN 2 chopsticks\t %d chopsticks left\n", pno + 1, chops);
    printf("Philosopher %d is THINKING\n", pno + 1); 
    test(LEFT); 
    test(RIGHT); 
    sem_post(&mutex); 
} 

void initialise(int pno) 
{ 
    pickup(pno); 
    putdown(pno); 
}

int main() 
{ 
    pid_t phil;

    for (int i=0; i<N; i++) 
        sem_init(&self[i], 0, 0); 

    sem_init(&mutex, 0, 1); 

    for (int i=0; i<N; i++) 
    {
        phil = fork();
        printf("Philosopher %d is THINKING\n", i + 1);
                
        if (phil == 0) 
        {
            initialise(i);
            exit(0);
        }
    }

    for (int i=0; i<N; i++) {
        wait(NULL);
    }

    for (int i=0; i<N; i++) 
        sem_destroy(&self[i]);
    sem_destroy(&mutex);

return 0;
}
