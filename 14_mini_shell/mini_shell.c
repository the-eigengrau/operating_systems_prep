/*

Project 14: The Mini-Shell (Fork & Exec)
Goal: Understanding Process creation.

Why: Threads share everything. Processes share nothing. P2 is all about Processes. You need to understand fork() deeply.

The Task:

Write a loop that prints myshell> .

Read a command (e.g., ls -la).

Call fork().

In the child: call execvp() to run the command.

In the parent: call waitpid() to wait for the child to finish.

*/