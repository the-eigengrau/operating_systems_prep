/*

Project 15: Shared Memory Ring Buffer
Goal: High-performance IPC.

Why: This is the core data structure for many IPC projects. Passing data between processes without copying it.

The Task:

Create a struct RingBuffer in Shared Memory (shm_open, mmap).

Process A writes integers into the buffer (Head index).

Process B reads integers from the buffer (Tail index).

Constraint: Handle the "wrap around" (when you hit the end of the buffer, go back to index 0) correctly in both processes.

*/