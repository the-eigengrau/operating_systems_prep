/*

Project 7: The "Invisible Handover" (Shared Memory)
Goal: Understand Process Isolation and Shared Memory. Why: In Projects 5 & 6, you used threads. Threads are easy because they share the same variables. Processes (which you use in GIOS Project 2) do not share memory. You have to explicitly ask the OS to map a chunk of RAM that two separate programs can see. Concepts: shm_open, mmap, ftruncate, sem_open (Semaphores).

The Task:

Create two completely separate C programs: writer.c and reader.c.

The Writer:

Creates a shared memory object named /my_shm.

Sizes it to hold an integer (4 bytes).

Maps it into memory.

Writes a random number to that memory address every second.

The Reader:

Opens that same /my_shm.

Maps it.

Prints the number it sees at that address every second.

The Synchronization (Crucial):

Without synchronization, the reader might read while the writer is halfway through writing.

Use a named semaphore (sem_open) to coordinate them. The Writer waits for the semaphore, writes, and signals.

Why this is "Intro to OS" Gold: This breaks the mental model that "variables are private." Seeing variable X change in Program B because Program A touched it feels like magic the first time you do it.

*/

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>

int main(){
    int shm_fd = shm_open("/my_shm", O_RDWR|O_CREAT, 0666);
    sem_t *sem_read = sem_open("/sem_read", O_CREAT, 0666, 0);
    sem_t *sem_write = sem_open("/sem_write", O_CREAT, 0666, 1);
    ftruncate(shm_fd, sizeof(int));
    int * ptr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED,shm_fd,0); 
    while(1) {
        sem_wait(sem_write);
        int random = rand() % 100;
        *ptr = random;
        printf("Random number is %d.\n", *ptr);
        sem_post(sem_read);
        sleep(1);

    }
}