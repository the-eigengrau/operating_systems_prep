/*

Project 5: The "Race Condition" Simulator
Goal: Understand why we need locks. Concepts: pthread_create, pthread_join, Race Conditions. The Project:

Create a global variable int counter = 0;.

Spawn 2 threads. Each thread runs a loop 1,000,000 times performing counter++.

Print the final value.

Observation: It won't be 2,000,000. It will be random and lower. This is a race condition.

The Fix: Introduce pthread_mutex_t. Lock before incrementing, unlock after. Verify the result is now exactly 2,000,000.

*/
#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <pthread.h>

int counter = 0;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

void * counter_worker() {

    for (size_t i=0;i < 1000000;i++){
        pthread_mutex_lock(&counter_lock);
        counter++;
        pthread_mutex_unlock(&counter_lock);
    }
    
    
}

int main() {
    pthread_t thread_id1;
    pthread_t thread_id2;
    
    pthread_create(&thread_id1, NULL, counter_worker, NULL);
    pthread_create(&thread_id2, NULL, counter_worker, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("Counter: %d\n", counter);

}