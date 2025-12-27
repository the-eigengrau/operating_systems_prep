/*

Project 09: Generic Map/Filter (void* & Function Pointers)
Goal: Master generic programming in C.

Why: GIOS libraries (like libcurl or threading libraries) rely heavily on "callbacks"—passing a function as an argument to another function.

The Task:

Write a function void map(void *array, int length, size_t item_size, void (*func)(void*)) .

It should take an array of any type (ints, structs) and apply func to every element.

Challenge: Pointer arithmetic on void* is illegal. You have to cast to char* and add item_size manually to iterate.

*/

