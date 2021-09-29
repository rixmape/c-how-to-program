// A program to test if initializing at least one element of an array
// will initialize the remaining array elements to the same value
// instead of zeros

#include <stdio.h>
#define SIZE 10

// Function main begins program execution
int main(void)
{
    int array[SIZE] = {13}; // Initialize first element

    puts("Arrays elements:");
    
    for (size_t i = 0; i < SIZE; ++i) {
        printf("  array[%u] = %d\n", i, array[i]);
    }
}

// Observation: Even though the first element was initialized to an integer
// other than zero, the remaining array elements were still set to zero.