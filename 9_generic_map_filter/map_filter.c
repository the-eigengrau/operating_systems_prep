/*

Project 09: Generic Map/Filter (void* & Function Pointers)
Goal: Master generic programming in C.

Why: GIOS libraries (like libcurl or threading libraries) rely heavily on "callbacks"—passing a function as an argument to another function.

The Task:

Write a function void map(void *array, int length, size_t item_size, void (*func)(void*)) .

It should take an array of any type (ints, structs) and apply func to every element.

Challenge: Pointer arithmetic on void* is illegal. You have to cast to char* and add item_size manually to iterate.

*/
#include <stdio.h>

 void map(void *array, int length, size_t item_size, void (*func)(void*)) {
    for (int i = 0; i < length; i++) {
        char* ptr = (char*)array + (item_size * i);
        func(ptr);
    }
 }

 void print_stuff(void* ptr) {
    int integer = *(int*)ptr;
    printf("Printing %d.\n", integer);
 }

 int main() {
    int integers[] = {1,2,3,4};
    int length = sizeof(integers) /sizeof(integers[0]);
    map(integers, 4, sizeof(int), print_stuff);
 }