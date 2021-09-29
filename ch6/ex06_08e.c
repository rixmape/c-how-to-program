// Exercise 6.8e: ex06_08e.c
// Find the largest and smallest elements of two dimensional array sales[4][5]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1 // Minimum value for the random number generator
#define MAX 999 // Maximum value for the random number generator

#define ROW 4 // Number of rows in array sales
#define COL 5 // Number of columns in array sales

int find_smallest(int array[ROW][COL]);
int find_largest(int array[ROW][COL]);

// Function main begins program execution
int main(void)
{
    int sales[ROW][COL]; // Declare two dimensional array sales
    srand(time(NULL)); // Seed the random number generator
    
    for (size_t x = 0; x < ROW; ++x) {
        for (size_t y = 0; y < COL; ++y) {
            sales[x][y] = MIN + rand() % (MAX + 1);
        }
    }

    // Find the maximum and minimum values in the array
    int smallest = find_smallest(sales);
    int largest = find_largest(sales);

    // Display the results
    printf("Smallest value is %d\n", smallest);
    printf("Largest value is %d", largest);
}

// Function find_smallest returns the minimum value in a two-dimensional array
int find_smallest(int array[ROW][COL])
{
    int minimum = array[0][0];
    for (size_t x = 0; x < ROW; ++x) {
        for (size_t y = 0; y < COL; ++y) {
            if (minimum > array[x][y]) {
                minimum = array[x][y];
            }
        }
    }

    return minimum;
}

// Function find_largest returns the maximum value in a two-dimensional array
int find_largest(int array[ROW][COL])
{
    int maximum = array[0][0];
    for (size_t x = 0; x < ROW; ++x) {
        for (size_t y = 0; y < COL; ++y) {
            if (maximum < array[x][y]) {
                maximum = array[x][y];
            }
        }
    }

    return maximum;
}