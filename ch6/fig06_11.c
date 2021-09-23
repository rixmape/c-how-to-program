// Fig. 6.11: fig06_11.c
// Static arrays are initialized to zero if not explicitly initialized.

#include <stdio.h>

void static_array_init(void); // Function prototype
void automatic_array_init(void); // Function prototype

// Function main begins program execution
int main(void)
{
    puts("First call to each function:");
    static_array_init();
    automatic_array_init();

    puts("\n\nSecond call to each function:");
    static_array_init();
    automatic_array_init();
}

// Function to demonstrate a static local array
void static_array_init(void)
{
    // Initializes elements to 0 before the function is called
    static int array1[3];

    puts("\nValues on entering static_array_init:");

    // Output contents of array1
    for (size_t i = 0; i <= 2; ++i) {
        printf("array1[%u] = %d  ", i, array1[i]);
    }

    puts("\nValues on exiting static_array_init:");

    // Modify and output contents of array1
    for (size_t i = 0; i <= 2; ++i) {
        printf("array1[%u] = %d  ", i, array1[i] += 5);
    }
}

// Function to demonstrate an automatic local array
void automatic_array_init(void)
{
    // Initializes elements each time function is called
    int array2[3] = {1, 2, 3};

    puts("\n\nValues on entering automatic_array_init:");

    // Output contents of array2
    for (size_t i = 0; i <= 2; ++i) {
        printf("array2[%u] = %d  ", i, array2[i]);
    }

    puts("\nValues on exiting automatic_array_init:");

    // Modify and output contents of array2
    for (size_t i = 0; i <= 2; ++i) {
        printf("array2[%u] = %d  ", i, array2[i] += 5);
    }
}