/*

Project 11: HTTP-Style Header Parser (State Machines)
Goal: Parsing text protocols securely.

Why: P1 requires you to parse a command like GETFILE /path/to/file \r\n. Doing this with scanf is buggy. You need to read byte-by-byte until you find \r\n\r\n.

The Task:

Create a function that takes a raw buffer (simulating a socket read).

Parse out a "Method" (GET), a "Path" (/index.html), and "Content-Length".

Constraint: Handle the case where the buffer ends halfway through the header (require a state machine).

*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_METHOD_LEN 16
#define MAX_PATH_LEN 1024
#define MAX_VERSION_LEN 1024
#define MAX_BODY_LEN 1024
#define MAX_KEY_LEN 512
#define MAX_VALUE_LEN 1024

typedef enum parser_states {
    STATE_METHOD,
    STATE_PATH,
    STATE_VERSION,
    STATE_HEADER_KEY,
    STATE_HEADER_VALUE,
    STATE_BODY,
} http_state;

struct http_parser {
    http_state state;
    char method[MAX_METHOD_LEN];
    char path[MAX_PATH_LEN];
    char version[MAX_VERSION_LEN];
    char header_key[MAX_KEY_LEN];
    char header_value[MAX_VALUE_LEN];
    char body[MAX_BODY_LEN];
    int content_length;
    size_t index;
};

void parse_byte(struct http_parser *p, char byte) {
    switch (p -> state) {
        case STATE_METHOD:
            if (byte != ' '){
                (p -> method)[p -> index] = byte;
                (p -> index) ++;}
            else{
                (p -> method)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_PATH;}
            break;
        case STATE_PATH:
           if (byte != ' '){
                (p -> path)[p -> index] = byte;
                (p -> index) ++;}
            else{
                (p -> path)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_VERSION;}
            break;
        case STATE_VERSION:
            char arr;
            if (byte == '\n'){
                (p -> version)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_HEADER_KEY;}
            else if (byte == '\r'){}
            else{
                (p -> version)[p -> index] = byte;
                (p -> index) ++;}
            break;
        case STATE_HEADER_KEY:
            if (byte == ':'){
                (p -> header_key)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_HEADER_VALUE;}
            else if (byte == '\n' ){
                (p -> header_key)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_BODY;}
            else if (byte == '\r'){}
            else{
                (p -> header_key)[p -> index] = byte;
                (p -> index) ++;}
            break;            
        case STATE_HEADER_VALUE:
            if (byte == '\n'){
                (p -> header_value)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_HEADER_KEY;
                if (strcmp(p-> header_key, ("Content-Length")) == 0) {
                    int length = atoi(p->header_value);
                    p -> content_length = length;
            }}
            else if (byte == '\r') {}
            else{
                (p -> header_value)[p -> index] = byte;
                (p -> index) ++;}


            break;
        case STATE_BODY:
            if (byte == '\n'){
                (p -> body)[p -> index] = '\0';
                p -> index = 0;
                (p -> state) = STATE_METHOD;}
            else if (byte == '\r') {}
            else{
                (p -> body)[p -> index] = byte;
                (p -> index) ++;}
            break;    
    }
}

int main() {
    struct http_parser parser;
    char test_request[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nContent-Length: 13\r\n\r\nHello, world!";
    parser.index = 0;
    parser.state = 0;

    for (int i = 0; i <sizeof(test_request) - 1; i++){
        parse_byte(&parser, test_request[i]);
    }

    printf("Parsing Complete!\n");
    printf("Method: '%s'\n", parser.method);
    printf("Path: '%s'\n", parser.path);
    printf("Content-Length: %d\n", parser.content_length);
    printf("Body: '%s'\n", parser.body);

    return 0;
}