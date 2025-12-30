/*

Project 10: Binary Struct Packer (Serialization)
Goal: Understand Memory Layout vs. Network Layout.

Why: You cannot just send(socket, &my_struct, ...) over the network. Different computers have different "Endianness" (byte order).

The Task:

Define a struct with an int, a short, and a char.

Write a serialize function that packs these into a generic char buffer using htonl (Host to Network Long) and htons.

Write a deserialize function that unpacks them back using ntohl.

*/

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

struct sample {
    int number;
    short small_number;
    char letter;
};

void serialize(struct sample *item, char *buffer) {
    int ordered_number = htonl(item -> number);
    memcpy(buffer, &ordered_number, sizeof(ordered_number));
    buffer += sizeof(int);

    short ordered_short = htons(item -> small_number);
    memcpy(buffer, &ordered_short, sizeof(short));
    buffer += sizeof(short);

    *buffer = item -> letter;
}

struct sample deserialize(char * buffer) {
    struct sample item;  
    int ordered_int;
    short ordered_short;
    
    memcpy(&ordered_int, buffer, sizeof(int));
    item.number = ntohl(ordered_int);
    buffer += sizeof(int);

    memcpy(&ordered_short, buffer, sizeof(short));
    item.small_number = ntohs(ordered_short);
    buffer += sizeof(short);

    item.letter = *buffer;

    return item;
}

int main() {
    struct sample item;
    item.number = 12;
    item.small_number = 10;
    item.letter = 'A';

    char buffer[sizeof(item)]; 
    
    serialize(&item, buffer);

    printf("Serialized Buffer (Hex): ");
    for (int i = 0; i < sizeof(int) + sizeof(short) + sizeof(char); i++) {
        printf("%02x ", (unsigned char)buffer[i]);
    }
    printf("\n");

    struct sample deserialized = deserialize(buffer);
    
    printf("Deserialized: %d, %d, %c\n", deserialized.number, deserialized.small_number, deserialized.letter);

    return 0;
}