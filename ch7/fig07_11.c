// Fig. 7.11: fig07_11.c
// Printing a string one character at a time using
// a non-constant pointer to constant data

#include <stdio.h>

void print_characters(const char *s_ptr);

int main(void)
{
    // Initialize char array
    char string[] = "print characters of a string";

    puts("The string is:");
    print_characters(string);
    puts("");
}

// s_ptr cannot be used to modify the character to which it points,
// i.e., s_ptr is a "read-only" pointer
void print_characters(const char *s_ptr)
{
    // Loop through entire string
    for(; *s_ptr != '\0'; ++s_ptr) { // No initialization
        printf("%c", *s_ptr);
    }
}