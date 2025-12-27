/*

Project 10: Binary Struct Packer (Serialization)
Goal: Understand Memory Layout vs. Network Layout.

Why: You cannot just send(socket, &my_struct, ...) over the network. Different computers have different "Endianness" (byte order).

The Task:

Define a struct with an int, a short, and a char.

Write a serialize function that packs these into a generic char buffer using htonl (Host to Network Long) and htons.

Write a deserialize function that unpacks them back using ntohl.

*/