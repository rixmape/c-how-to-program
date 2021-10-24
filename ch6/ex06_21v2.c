// Exercise 6.21 version 2: ex06_21v2.c
// Computing the sum of the products of the elements within
// a row from a two dimensional matrix and the associated
// elements of a column of another two dimensional matrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIDE 3

void fill_mat(int mat_row, int mat_col, int mat[mat_row][mat_col]);

int main(void)
{
    // Obtain dimensions of the first matrices
    int row1, col1;
    printf("First matrix (row, col): ");
    scanf("%d%d", &row1, &col1);

    // Obtain dimensions of the second matrices
    int row2, col2;
    printf("\nSecond matrix (row, col): ");
    scanf("%d%d", &row2, &col2);

    // Declare the two 2D matrices
    int mat1[row1][col1];
    int mat2[row2][col2];

    // Seed random number generator
    srand(time(NULL));

    // Generate random values for the matrices
    puts("\n\nMatrix No. 1:");
    fill_mat(row1, col1, mat1);
    puts("\nMatrix No. 2");
    fill_mat(row2, col2, mat2);

    // Determine the number of sums that will be stored
    int size = row1 < col2 ? row1 : col2;
    
    // Initialize array for the sums
    unsigned int sums[size];

    // Loop through each row of the first matrix
    for (size_t x = 0; x < size; ++x) {

        sums[x] = 0;

        // Loop through each element of the current row
        for (size_t y = 0; y < col1; ++y) {

            // Compute and store the sum
            sums[x] += mat1[x][y] * mat2[y][x];
        }
    }

    // Display the results
    puts("\nSums:");
    for (size_t i = 0; i < SIDE; ++i) {
        printf("  sums[%u] == %u\n", i, sums[i]);
    }
}

// Fill up the matrix with random values
void fill_mat(int mat_row, int mat_col, int mat[mat_row][mat_col])
{
    // Loop through each row of the matrix
    for (size_t x = 0; x < mat_row; ++x) {
        
        // Loop through each column in the current row
        for (size_t y = 0; y < mat_col; ++y) {

            // Generate and store random value
            int val = 1 + rand() % 10;;
            mat[x][y] = val;

            // Print value
            printf("%4d", val);
        }

        puts("");
    }

}