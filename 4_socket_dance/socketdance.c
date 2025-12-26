#include <stdio.h>      // For printf
#include <stdlib.h>     // For exit()
#include <string.h>     // For memset
#include <unistd.h>     // For read, write, close
#include <sys/types.h>
#include <sys/socket.h> // The main socket header
#include <netinet/in.h> // For the internet address structures

int main {

    // why is a socket called a socket? What are other common argument values for sockets?
    // How come a server can have a fd? I think of servers and files as very different.
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd == -1) {
        printf("invalid socket");
        return 1;
    }

    struct sockaddr_in address;
    // what other fields and params are in this struct? What are AF_INET and INADDR_ANY again? Do I have to memorize all these?
    address.sin_family = AF_INET;
    address.sin_address.s_addr = INADDR_ANY;
    // what's the deal with byte order? what does htons actually do? What does it stand for?
    address.sin_port = htons(8888);

    //How does this bind command actually work?
    bind(server_fd, sockaddr_in, sizeof(address));
    //How does the listen command actually work? How does the backlog work? What should we typically set it at?
    listen(server_fd, 10);



    return 0
}