/*

Project 6: The Boss-Worker Queue
Goal: Combine structs, pointers, and threading. Concepts: Condition Variables (pthread_cond_wait), Producer-Consumer pattern. The Project: GIOS Project 1 uses a "Boss-Worker" model where one thread listens for connections and hands them off to worker threads.

Create a struct Queue (linked list from Project 2 logic).

Boss Thread: Pushes random numbers into the queue every 1 second.

Worker Threads (create 4 of them): They sit in a loop waiting for numbers.

The Logic: Use a Condition Variable.

Workers shouldn't "busy wait" (infinite loop checking if queue is empty). They should sleep (cond_wait).

When the Boss pushes a number, it signals (cond_signal) to wake up a worker.

*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Node {
    int data;
    struct Node * next;
};

struct Queue {
    struct Node * head;
    struct Node * tail;
    pthread_mutex_t lock;
    pthread_cond_t cond;
};

void init_queue(struct Queue *q) {
    q -> head = NULL;
    q -> tail = NULL;
    pthread_mutex_init(&(q -> lock), NULL);
    pthread_cond_init(&(q -> cond),NULL);
}

void push(struct Queue *q, int data) {

    pthread_mutex_lock(&(q -> lock));
    if (q -> head == NULL) {
        struct Node * new_node = malloc(sizeof(struct Node));
        new_node -> data = data;
        new_node -> next = NULL;
        q -> head = new_node;
        q -> tail = new_node;
    } else {
        struct Node * new_node = malloc(sizeof(struct Node));
        new_node -> data = data;
        new_node -> next = NULL;
        q -> tail -> next = new_node;
        q -> tail = new_node;
    }
    pthread_cond_signal(&(q -> cond));
    pthread_mutex_unlock(&(q -> lock));

}

int pop(struct Queue * q) {
    pthread_mutex_lock(&(q -> lock));
    while (q -> head == NULL) {
        pthread_cond_wait(&(q -> cond), &( q-> lock));
    }
    struct Node * popped_node = q -> head;
    int data = popped_node -> data;
    q -> head = q -> head -> next;
    if (q -> head == NULL) {
        q -> tail = NULL;
    }
    free(popped_node); 
    pthread_mutex_unlock(&(q->lock));
    
    return data;
}

void * boss_thread(void * arg) {
    struct Queue * q = (struct Queue *)arg;
    while(1) {
        int data = rand() % 100;
        push(q, data);
        printf("Boss thread pushed %d.\n", data);
        sleep(1);
    }
}

void * worker_thread(void * arg) {
    struct Queue * q = (struct Queue *)arg;
    while(1) {
        int data = pop(q);
        printf("Worker thread ID %ld pulled %d.\n", pthread_self(), data);
    }
}

int main() {
    pthread_t boss;
    pthread_t worker1;
    pthread_t worker2;
    pthread_t worker3;
    pthread_t worker4;

    struct Queue * q = malloc(sizeof(struct Queue));
    init_queue(q);

    pthread_create(&boss, NULL, boss_thread, q);
    pthread_create(&worker1, NULL, worker_thread, q);
    pthread_create(&worker2, NULL, worker_thread, q);
    pthread_create(&worker3, NULL, worker_thread, q);
    pthread_create(&worker4, NULL, worker_thread, q);
    pthread_join(boss, NULL);
    pthread_join(worker1, NULL);
    pthread_join(worker2, NULL);
    pthread_join(worker3, NULL);
    pthread_join(worker4, NULL);
}
