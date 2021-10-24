// Fig. 7.21: fig07_21.c
// Copying a string using array notation and pointer notation.

#include <stdio.h>
#define SIZE 10

void copy1(char * const s1, const char * const s2);
void copy2(char *s1, const char *s2);

int main(void)
{
    char string1[SIZE];
    char *string2 = "Hello"; // Create a pointer to a string

    copy1(string1, string2); // Copy strings by array indexing
    printf("string1 = %s\n", string1);

    char string3[SIZE];
    char string4[] = "Good Bye";

    copy2(string3, string4); // Copy strings by pointer arithmetic
    printf("string3 = %s\n", string3);
}

// For functions copy1 and copy2, the first argument must be an array
// large enough to hold the string in the second argument
void copy1(char * const s1, const char * const s2)
{
    // Loop through strings
    for (size_t i = 0; (s1[i] = s2[i]) != '\0'; ++i) {
        ; // Do nothing in body
    }
}

// s1 is not declared as constant pointer since ++s1
// modifies the memory location that s1 points to,
// same logic applies to s2 
void copy2(char *s1, const char *s2)
{
    // Loop through strings
    for (; (*s1 = *s2) != '\0'; ++s1, ++s2) {
        ; // Do nothing in body
    }
}
