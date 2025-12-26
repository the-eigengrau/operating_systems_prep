/*

Project 3: The "Syscall" File Copy

Goal: Understand File Descriptors vs. File Pointers. Concepts: open, read, write (System Calls) vs fopen, fread (Standard Lib). The Project: In OS code, you often use raw system calls (unbuffered) rather than standard libraries.

Write a program mycp that copies a binary file from Source to Dest.

Use open(), read(), and write() (include <unistd.h> and <fcntl.h>).

Create a buffer of 1024 bytes. Read into the buffer, write out from the buffer.

Crucial logic: Handle the case where read returns fewer bytes than requested (partial reads)—this logic is identical to reading network packets later.

*/

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