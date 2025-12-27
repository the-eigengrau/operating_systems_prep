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

//int shm_fd = shm_open(const char *name, O_WRONLY|O_CREAT, mode_t mode)