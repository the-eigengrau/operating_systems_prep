/*

Project 08: The Segfault Hunt (GDB Mastery)
Goal: Stop using printf to debug. Learn to use gdb (GNU Debugger).

Why: In GIOS, you will get segfaults in threads where printf won't help you (output buffering issues). You must know how to read a stack trace.

The Task:

I will provide you with a purposefully broken C program (dereferencing null, double free, stack overflow).

Compile it with -g.

Run it, let it crash.

Use gdb core or gdb ./a.out to find exactly which line crashed and print the variables at that moment.

*/