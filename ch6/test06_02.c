/* Objective:
 * To modify the size of a variable-length array after its definition.
 * 
 * Conclusion:
 * The size of a variable-length array cannot be changed by merely
 * redefining the variable that holds the value of its initial size.
 */

#include <stdio.h>

void set_array(int array[], size_t size);
void print_size(int array[]);

// Function main begins program execution
int main(void)
{
    // Set the initial size of the array
    size_t length = 3;
    printf("Initial value of variable length is %u\n", length);
    int numbers[length];

    set_array(numbers, length); // Initialize the elements of the array
    print_size(numbers); // Print the size of the array

    // Change the variable holding the initial size of the array
    length = 5;
    printf("\nNew value of variable length is %u\n", length);

    set_array(numbers, length);
    print_size(numbers);
}

// Initialize the elements of the array
void set_array(int array[], size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        array[i] = (i + 1) * 2; // Set each element to the multiples of 2
    }
}

// Print the number of elements in the array
void print_size(int *array)
{
    int num_elements = sizeof(array) / sizeof(array[0]);
    printf("Real size of the array is %u\n", num_elements);
}