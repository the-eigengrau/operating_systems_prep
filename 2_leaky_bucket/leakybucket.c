/*

Project 2: The leaky_bucket.c
Goal: Master malloc, free, and valgrind. Concepts: Heap memory, struct pointers, memory leaks. The Project: GIOS requires you to manage memory manually. If you leak memory in long-running servers, you fail.

Define a struct Student with a generic ID and a name (char pointer).

Write a function that allocates a Student and their name on the heap (malloc).

Write a main loop that creates 100 students and prints them.

The Catch: Intentionally forget to free() the memory. Run it with valgrind --leak-check=full ./a.out inside your container to see the error.

The Fix: Fix the code to properly free both the struct and the name. Get Valgrind to report "0 bytes in 0 blocks" lost.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student {
    int id;
    // pointer to a string
    char *name;
};

//function expects a pointer to the student struct
void free_student(struct Student* s) {
    free(s->name);
    free(s);
}

struct Student* create_student(int id, char *name) {
    struct Student *s = malloc(sizeof(struct Student));
    s -> id = id;
    //pointer to a memory block
    char *name_address = malloc(strlen(name)+1);
    s -> name = name_address;
    strcpy(s -> name, name);
    return s;
};

int main() {
    int id = 0;
    for (id; id<10; id++) {
        struct Student *s = create_student(id, "Student");
        printf("ID %d\n: ", s -> id);
        printf("Name %s\n:", s -> name);
        free_student(s);
    }
}

