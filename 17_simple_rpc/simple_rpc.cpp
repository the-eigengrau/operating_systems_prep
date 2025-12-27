/*

Project 17: Simple RPC (Remote Procedure Call)
Goal: Calling a function on another computer.

Why: Project 3 is often about distributed file systems or gRPC. You need to understand the concept of a "Stub".

The Task:

Server: Listens for a packet containing { int op_code, int a, int b }. If op_code is 1, it adds a+b and sends the result back.

Client: Defines a function int add_remote(int a, int b). When called, it doesn't add them—it packages them into a struct, sends them to the server, waits for the response, and returns it.

To the main() function in the client, it looks like a local function call!

*/