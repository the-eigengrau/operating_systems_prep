#include <stdio.h>  
#include <fcntl.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <dest>\n", argv[0]);
        return 1;
    }

    // generate a read only file descriptor representing the source
    int src_fd = open(argv[1], O_RDONLY);

    if (src_fd == -1) {
        printf("Invalid source");
        return 1;
    }

    // generate a write, create, or delete file descriptor for the destination
    int dest_fd = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666);

    if (dest_fd == -1) {
        printf("Invalid dest");
        return 1;
    }

    char buffer[1024];

    ssize_t bytes_read;
    ssize_t bytes_write;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {  
        bytes_write = write(dest_fd, buffer, bytes_read);
        
    }

    close(src_fd);
    close(dest_fd);

}