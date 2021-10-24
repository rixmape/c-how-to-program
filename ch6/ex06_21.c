// Exercise 6.21: ex06_21.c
// Computing the sum of the products of the elements within
// a row from a two dimensional matrix and the associated
// elements of a column of another two dimensional matrix.

#include <stdio.h>
#define SIDE 3

int main(void)
{
    // Initialize the two 2D matrices
    int mat1[][SIDE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[][SIDE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Initialize array for the sums
    unsigned int sums[SIDE] = {0};

    // Loop through each row of the first matrix
    for (size_t x = 0; x < SIDE; ++x) {

        // Loop through each element of the current row
        for (size_t y = 0; y < SIDE; ++y) {

            // Compute and store the sum
            sums[x] += mat1[x][y] * mat2[y][x];
        }
    }

    // Display the results
    for (size_t i = 0; i < SIDE; ++i) {
        printf("sums[%u] == %u\n", i, sums[i]);
    }
}