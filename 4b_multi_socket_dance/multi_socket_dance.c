/*
Project 4b: The Multi-Threaded TCP Echo Server

Goal: Learn concurrency and the "Manager-Worker" pattern.
Concepts: pthreads, pthread_create, pthread_detach, memory sharing (malloc/free).

The Project:
1. Create a server that listens on port 8888.
2. The Main Thread (Manager) blocks on accept().
3. When a client connects, the Manager spawns a NEW Worker Thread to handle that specific client.
4. The Manager immediately goes back to accept() to wait for the next person.
5. The Worker Thread reads/writes until the client says "quit", then closes the socket and kills itself.
*/

#include <stdio.h>      
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <pthread.h>

void * read_write_worker(void * new_socket) {
    char buffer[1024];
    int socket = *(int *)new_socket;
    free(new_socket);

     while(1) {
            
            int client_read = read(socket, buffer, 1024);

            if (client_read <=0) {
                break;
            }

            if (strncmp(buffer, "quit", 4) == 0) {
                break;
            }
        
            write(socket, buffer, client_read);
        }
        close(socket);
        printf("Socket closed and freed.\n");
    
}

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

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if ((bind(server_fd, (struct sockaddr *)&address, sizeof(address))) == -1) {
        perror("bind failed.");
        return 1;
    }

    listen(server_fd, 10);

     while(1) {
        pthread_t thread_id;
        socklen_t addrlen = sizeof(address);
        int * new_socket = malloc(sizeof(int));
        *new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        printf("Client connected.\n");
        pthread_create(&thread_id, NULL, read_write_worker, new_socket);
        pthread_detach(thread_id);
    }

    return 0;
}