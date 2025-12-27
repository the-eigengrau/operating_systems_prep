/*

Project 6: The Boss-Worker Queue (The Capstone)
Goal: Combine structs, pointers, and threading. Concepts: Condition Variables (pthread_cond_wait), Producer-Consumer pattern. The Project: GIOS Project 1 uses a "Boss-Worker" model where one thread listens for connections and hands them off to worker threads.

Create a struct Queue (linked list from Project 2 logic).

Boss Thread: Pushes random numbers into the queue every 1 second.

Worker Threads (create 4 of them): They sit in a loop waiting for numbers.

The Logic: Use a Condition Variable.

Workers shouldn't "busy wait" (infinite loop checking if queue is empty). They should sleep (cond_wait).

When the Boss pushes a number, it signals (cond_signal) to wake up a worker.

*/