/*

Project 11: HTTP-Style Header Parser (State Machines)
Goal: Parsing text protocols securely.

Why: P1 requires you to parse a command like GETFILE /path/to/file \r\n. Doing this with scanf is buggy. You need to read byte-by-byte until you find \r\n\r\n.

The Task:

Create a function that takes a raw buffer (simulating a socket read).

Parse out a "Method" (GET), a "Path" (/index.html), and "Content-Length".

Constraint: Handle the case where the buffer ends halfway through the header (require a state machine).

*/