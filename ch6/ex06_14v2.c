// Exercise 6.14: ex06_14.c
// Using one-dimensional array to get the union of two sets

#include <stdio.h>
#define SIZE 10

int create_union(int union_array[], int array1[SIZE], int array2[SIZE]);

int main(void)
{
    // Initialize the two arrays that will be compared
    int set1[SIZE] = {6, 24, 98, 51, 60, 31, 41, 26, 64, 27};
    int set2[SIZE] = {89, 24, 78, 41, 64, 66, 50, 12, 19, 2};

    // Declare the array that will contain the elements of the union set
    // with elements equal to the sum of elements in the two arrays
    int union_set[SIZE * 2];

    // Initialize values of the union set
    int unique_elements = create_union(union_set, set1, set2);

    // Display elements in union set
    puts("Elements in union set:");
    for (size_t i = 0; i < unique_elements; ++i) {
        printf("%4d", union_set[i]);
    }
}

// Function create_union initialize the elements of the union set, and
// returns the number of elements in the set
int create_union(int union_array[], int array1[SIZE], int array2[SIZE])
{
    // Include all elements of the first set to the union set
    for (size_t i = 0; i < SIZE; ++i) {
        union_array[i] = array1[i];
    }

    // Initialize the counter variable for unique elements
    int z = SIZE;

    // Loop for each element of array2
    for (size_t x = 0; x < SIZE; ++x) {

        int match = 0; // Initialize the flag variable for matching elements 

        // Loop for each element of array1
        for (size_t y = 0; y < SIZE; ++y) {
            if (array2[x] == array1[y]) {
                match = 1;
                break; // Break loop once a match is found
            }
        }

        // Append unique element from set2, compared to set1, to the union set
        if (match == 0) {
            union_array[z] = array2[x];
            ++z;
        }

    }

    return z; // Return the number of unique elements
}