// Fig. 6.10: fig06_10.c
// Treating character arrays as strings

#include <stdio.h>
#define SIZE 20

// Function main begins program execution
int main(void)
{
    char string1[SIZE]; // Reserves 20 characters
    char string2[] = "string literal"; // Reserves 15 characters

    // Read string from user into array string1
    printf("%s", "Enter a string (no longer than 19 characters): ");
    scanf("%19s", string1); // Input no more than 19 characters

    // Output strings
    printf("string1 is: %s\nstring2 is: %s\n"
            "string1 with spaces between characters is:\n",
            string1, string2);

    // Output characters until null character is reached
    for (size_t i = 0; i < SIZE && string1[i] != '\0'; ++i) {
        printf("%c ", string1[i]);
    }
    
    puts("");
}