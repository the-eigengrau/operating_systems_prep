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

