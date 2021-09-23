// Fig. 6.23: fig06_23.c
// Using variable-length arrays in C99

#include <stdio.h>

void print_1d_array(size_t size, int array[size]);
void print_2d_array(int row, int col, int array[row][col]);

int main(void)
{
    printf("%s", "Enter size of one-dimensional array: ");
    int array_size; // Size of 1-D array
    scanf("%d", &array_size);

    int array[array_size]; // Declare 1-D variable-length array

    printf("%s", "Enter number of rows and columns in a 2-D array: ");
    int row1, col1; // Number of rows and columns in a 2-D array
    scanf("%d %d", &row1, &col1);

    int array2d_1[row1][col1]; // Declare 2-D variable-length array

    printf("%s", "Enter number of rows and columns in another 2-D array: ");
    int row2, col2; // Number of rows and columns in another 2-D array
    scanf("%d %d", &row2, &col2);

    int array2d_2[row2][col2]; // Declare 2-D variable-length array

    // Test sizeof operator on VLA
    printf("\nsizeof(array) yields array size of %d bytes\n", sizeof(array));

    // Assign elements of 1-D VLA
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = i * i;
    }

    // Assign elements of first 2-D VLA
    for (size_t i = 0; i < row1; ++i) {
        for (size_t j = 0; j < col1; ++j) {
            array2d_1[i][j] = i + j;
        }
    }

    // Assign elements of second 2-D VLA
    for (size_t i = 0; i < row2; ++i) {
        for (size_t j = 0; j < col2; ++j) {
            array2d_2[i][j] = i + j;
        }
    }

    puts("\nOne-dimensional array:");
    print_1d_array(array_size, array); // Pass 1-D VLA to function

    puts("\nFirst two-dimensional array:");
    print_2d_array(row1, col1, array2d_1); // Pass 2-D VLA to function

    puts("\nSecond two-dimensional array:");
    print_2d_array(row2, col2, array2d_2); // Pass other 2-D VLA to function
}

void print_1d_array(size_t size, int array[size])
{
    // Output contents of array
    for (size_t i = 0; i < size; ++i) {
        printf("array[%d] = %d\n", i, array[i]);
    }
}

void print_2d_array(int row, int col, int array[row][col])
{
    // Output contents of array
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            printf("%5d", array[i][j]);
        }
    
        puts(""); 
    }
}