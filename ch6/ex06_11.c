// Exercise 6.11: ex06_11.c
// Selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function main begins program execution
int main(void)
{
    int numbers[SIZE]; // Declare array numbers
    
    // Initialize and print the values of array numbers
    printf("%18s", "Original sequence:");
    srand(time(NULL)); // Randomize the random number generator
    for (size_t i = 0; i < SIZE; ++i) {
        numbers[i] = 1 + rand() % 100;
        printf("%3d", numbers[i]);
    }

    // Loop from the second position
    // Consider elements from the x position of array numbers as a sub-array
    for (size_t x = 1; x < SIZE; ++x) {

        // Loop for each element of the sub-array
        for (size_t y = x; y < SIZE; ++y) {
            
            // Check if the value of the element immediately before the
            // first element of the sub-array is greater than the value
            // of current element in the sub-array
            if (numbers[x-1] > numbers[y]) {
                
                // Swap the value of the current element with the value
                // of the element before the sub-array
                int temp = numbers[x-1];
                numbers[x-1] = numbers[y];
                numbers[y] = temp;
            }
        }
    }

    // Display results
    printf("\n%18s", "Sorted sequence:");
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%3d", numbers[i]);
    }
}