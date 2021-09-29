// Exercise 6.14: ex06_14.c
// Using one-dimensional array to get the union of two sets

#include <stdio.h>
#define SIZE 10

int get_unique(int array1[SIZE], int array2[SIZE]);
void create_union(int union_array[], int array1[SIZE], int array2[SIZE]);

int main(void)
{
    // Initialize the two arrays that will be compared
    int set1[SIZE] = {6, 24, 98, 51, 60, 31, 41, 26, 64, 27};
    int set2[SIZE] = {89, 24, 78, 41, 64, 66, 50, 12, 19, 2};

    // Determine and print the number of unique elements in the
    // two arrays, which is the size of the union set
    int unique = get_unique(set1, set2);
    printf("Number of unique elements (size of union set): %u\n\n", unique);

    // Declare the array that will contain the elements of the union set
    int union_set[unique];

    create_union(union_set, set1, set2);

    // Display elements in union set
    puts("Elements in union set:");
    for (size_t i = 0; i < unique; ++i) {
        printf("%4d", union_set[i]);
    }
}

// Function get_unique returns the number of unique elements in two arrays
int get_unique(int array1[SIZE], int array2[SIZE])
{
    // Initialize distinct to the lowest possible number of unique values
    int distinct = SIZE;

    // Loop for each element of array2
    for (size_t x = 0; x < SIZE; ++x) {

        int match = 0; // Initialize the flag variable for matching numbers 

        // Loop for each element of array1
        for (size_t y = 0; y < SIZE; ++y) {

            // Compare the elements of the two arrays
            if (array2[x] == array1[y]) {
                match = 1;
                break; // Break loop once a match is found
            }
        }

        if (match == 0) {
            ++distinct; // Increment number of unique values
        }
    }

    return distinct;
}

// Function create_union initialize the elements of the union set 
void create_union(int union_array[], int array1[SIZE], int array2[SIZE])
{
    // Include all elements of the first set to the union set
    for (size_t i = 0; i < SIZE; ++i) {
        union_array[i] = array1[i];
    }

    // Initialize the counter variable for unique elements
    int unique_element = SIZE;

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

        // Append unique elements in set2, as compared to set1, to union_set
        if (match == 0) {
            union_array[unique_element] = array2[x];
            ++unique_element;
        }

    }
}