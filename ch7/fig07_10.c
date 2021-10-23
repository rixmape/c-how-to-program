// Fig. 7.10: fig07_10.c
// Converting a string to uppercase using a
// non-constant pointer to non-constant data.

#include <stdio.h>
#include <ctype.h>

void convert_to_uppercase(char *s_ptr);

int main(void)
{
    char string[] = "cHaRaCters and $32.98";

    printf("The string before conversion is: %s", string);
    convert_to_uppercase(string);
    printf("\nThe string after conversion is: %s\n", string);
}

// Convert string to uppercase letters
void convert_to_uppercase(char *s_ptr)
{
    while (*s_ptr != '\0') {
        *s_ptr = toupper(*s_ptr);
        ++s_ptr;
    }
}