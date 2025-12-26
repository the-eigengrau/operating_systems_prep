/*

Project 4: The TCP Echo Server

Goal: Learn the socket "dance." Concepts: socket, bind, listen, accept. The Project: This is the skeleton of GIOS Project 1.

Create a server that listens on port 8888.

Block on accept() waiting for a client.

When a client connects (test using telnet localhost 8888 or nc), read what they type and send it back to them.

Close the connection when they type "quit".

*/

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h> 

int main() {

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        printf("invalid socket");
        return 1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8888);

    if ((bind(server_fd, (struct sockaddr *)&address, sizeof(address))) == -1) {
        perror("bind failed.");
        return 1;
    }

    listen(server_fd, 10);

    while(1) {
        socklen_t addrlen = sizeof(address);
        int new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        printf("Client connected.\n");
        char buffer[1024];
        
        while(1) {
            int client_read = read(new_socket, buffer, 1024);

            if (client_read <=0) {
                break;
            }

            if (strncmp(buffer, "quit", 4) == 0) {
                break;
            }
        
            write(new_socket, buffer, client_read);
        }
        close(new_socket);
        printf("Socket closed.\n");
    }

    return 0;
}