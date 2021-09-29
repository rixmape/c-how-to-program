// Fig. 6.15: fig06_15_v2.c
// Sorting an array of randomly generated values in an ascending order

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100 // Size of array

// Function main begins program execution
int main(void)
{
    int a[SIZE] = {0}; // Initialize array to zeros

    srand(time(NULL)); // Seed random number generator
    
    // Loop to initialize each array element
    for (size_t x = 0; x < SIZE; ++x) {
        a[x] = 1 + rand() % 1000; // Generate random integer from 1 to 999
    }

    puts("Data items in original order");

    // Output original array
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
        if ((i + 1) % 20 == 0) {
            puts(""); // Print newline after every 20 characters
        }
    }

    // Bubble sort
    // Loop to control number of passes
    for (unsigned int pass = 1; pass < SIZE; ++pass) {

        // Loop to control number of comparisons per pass
        for (size_t i = 0; i < SIZE - 1; ++i) {

            // Compare adjacent elements and swap them if
            // first element is greater than the second element
            if (a[i] > a[i + 1]) {
                int hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
        }
    }

    puts("\nData items in ascending order");

    // Output sorted array
     for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
        if ((i + 1) % 20 == 0) {
            puts(""); // Print newline after every 20 characters
        }
    }
    
    puts("");
}