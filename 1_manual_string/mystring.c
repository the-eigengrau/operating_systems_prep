/*

Project 1: The "Manual" String Library
Goal: Understand pointers, array decay, and null terminators. Concepts: char*, pointer arithmetic, \0. The Project: Python handles strings automatically. In C, a string is just an array of bytes ending in a null byte.

Create mystring.c.

Implement your own version of strlen (string length) and strcpy (string copy) without using <string.h>.

Constraint: You cannot use array indexing (e.g., str[i]). You must use pointer arithmetic (e.g., *str, str++).

Test: Write a main function that tests these against the real versions.

*/

#include <stdio.h>
#include <string.h>

size_t my_str_len(const char *str) {
  size_t length = 0;
  while (*str != '\0') {
    length += 1;
    str++;
  }
  return length;

}

void my_str_cpy(const char *source, char *target) {
  while (*source != '\0') {
    *target = *source;
    source++;
    target++;
}
  *target = '\0';
}

int main() {
  const char *source = "Hello, C!";
  char dest[50];

  printf("Mine: %zu\n", my_str_len(source));
  printf("Real: %zu\n", strlen(source));

  my_str_cpy(source, dest);
  printf("My Copy: %s\n", dest);

  strcpy(dest, source);
  printf("Real copy: %s\n", dest);

  return 0;
}