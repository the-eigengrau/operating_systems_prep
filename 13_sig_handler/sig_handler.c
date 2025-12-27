/*

Project 13: Signal Handler ("Graceful Shutdown")
Goal: Handling OS interruptions.

Why: If you Ctrl+C your server, does it clean up memory? If a client disconnects mid-write (SIGPIPE), does your server crash?

The Task:

Write a program that runs an infinite loop printing "Working...".

Register a signal handler for SIGINT (Ctrl+C).

When you hit Ctrl+C, the program should catch it, print "Cleaning up...", and exit cleanly with code 0.

*/