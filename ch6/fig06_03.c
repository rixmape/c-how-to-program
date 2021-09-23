// Fig. 6.3: fig06_03.c
// Initializing the elements of an array to zeros.

#include <stdio.h>

// Function main begins program execution
int main(void)
{
    int n[5]; // n is an array of five integers

    // Set elements of array to 0
    for (size_t i = 0; i < 5; ++i) {
        n[i] = 0; // Set element at location i to 0
    }

    printf("%s%13s\n", "Element", "Value");

    // Output contents of array n in tabular format
    for (size_t i = 0; i < 5; ++i) {
        printf("%7u%13d\n", i, n[i]);
    }
}