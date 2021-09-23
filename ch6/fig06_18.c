// Fig. 6.18: fig06_18.c
// Linear search of an array

#include <stdio.h>
#define SIZE 100

// Function prototype
size_t linear_search(const int array[], int key, size_t size);

// Function main begins program execution
int main(void)
{
    int a[SIZE]; // Create array a

    // Create some data
    for (size_t x = 0; x < SIZE; ++x) {
        a[x] = 2 * x;
    }

    // Enter integer search key
    int search_key; // Value to locate in array a
    scanf("%d", &search_key);

    // Attempt to locate search_key in array a
    size_t index = linear_search(a, search_key, SIZE);

    // Display results
    if (index != -1) {
        printf("Found value at index %d\n", index);
    } else {
        puts("Value not found");
    }
}

// Compare key to every element of array until the location is found
// or until the end of array is reached; return index of element
// if key is found or -1 if key is not found
size_t linear_search(const int array[], int key, size_t size) 
{
    // Loop through array
    for (size_t n = 0; n < size; ++n) {

        if (array[n] == key) {
            return n; // Return location of key
        }
    }

    return -1; // Key not found
}