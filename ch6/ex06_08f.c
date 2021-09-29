// Exercise 6.8f: ex06_08f.c
// Determine and store the sum and difference of the values
// contained in two, 100-element double arrays d1 and d2,
// into double arrays sum and difference

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 100

void set_values(double array[SIZE]);
void print_array(double array[SIZE]);
void subtract(double array1[SIZE], double array2[SIZE], double array3[SIZE]);
void add(double array1[SIZE], double array2[SIZE], double array3[SIZE]);

// Function main begins program execution
int main(void)
{
    // Declare arrays d1 and d2
    double d1[SIZE], d2[SIZE];

    // Declare container arrays for the sum and difference of d1 and d2
    double difference[SIZE], sum[SIZE];
    
    srand(time(NULL)); // Seed random number generator

    // Initialize array elements of the two arrays
    set_values(d1);
    puts("Values contained in array d1: ");
    print_array(d1);

    set_values(d2);
    puts("Values contained in array d2: ");
    print_array(d2);
    
    // Subtract and add the values contained from arrays d2 and d1
    subtract(d1, d2, difference);
    add(d1, d2, sum);

    // Display the sum and difference
    puts("Difference of values contained in two arrays: ");
    print_array(difference);
    puts("Sum of values contained in two arrays: ");
    print_array(sum);
}

// Function set_values initializes the elements of an array
void set_values(double array[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i) {
        // Randomly generate rational number from 1.000 to 999.999
        double fraction = (1 + rand() % 1000) * 0.001;
        double number = (1 + rand() % 1000) + fraction;

        // Initialize element of the array
        array[i] = number;
    }
}

// Function print_array prints the elements of an array
void print_array(double array[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i) {
        if (i % 5 == 0) {
            puts(""); // Output new line every after 20 values
        }

        printf("%18.3f", array[i]);
    }

    puts("");
    puts("");
}

// Function subtract stores the difference of two arrays in another array
void subtract(double array1[SIZE], double array2[SIZE], double array3[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i) {
        array3[i] = array2[i] - array1[i];
    }
}

// Function add stores the sum of two arrays in another array
void add(double array1[SIZE], double array2[SIZE], double array3[SIZE])
{
    for (size_t i = 0; i < SIZE; ++i) {
        array3[i] = array2[i] + array1[i];
    }
}