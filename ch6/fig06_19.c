// Fig. 6.19: fig06_19.c
// Binary search of a sorted array

#include <stdio.h>
#define SIZE 20

// Function prototypes
size_t binary_search(const int b[], int search_key, size_t low, size_t high);
void print_header(void);
void print_row(const int b[], size_t low, size_t mid, size_t high);

// Function main begins program execution
int main(void)
{
    int a[SIZE]; // Create array a

    // Create data
    for (size_t i = 0; i < SIZE; ++i) {
        a[i] = 2 * i;
    }

    printf("Enter a number between 0 and %d: ", a[SIZE - 1]);
    int key; // Value to locate in array a
    scanf("%d", &key);

    print_header();

    // Search for key in array a
    size_t result = binary_search(a, key, 0, SIZE - 1);

    // Display results
    if (result != -1) {
        printf("\n%d found at index %d\n", key, result);
    } else {
        printf("\n%d not found\n", key);
    }
}

// Function to perform binary search of an array
size_t binary_search(const int b[], int search_key, size_t low, size_t high)
{
    // Loop until low index is greater than high index
    while (low <= high) {

        // Determine middle element of the subarray being searched
        size_t middle = (low + high) / 2;

        // Display subarray used in this loop iteration
        print_row(b, low, middle, high);

        // If search_key matched middle element, return middle
        if (search_key == b[middle]) {
            return middle;
        }

        // If search_key is less than middle element, set new high
        else if (search_key < b[middle]) {
            high = middle - 1; // Search low end of array
        }

        // If search key is greater than middle element, set new low
        else {
            low = middle + 1; // Search high end of array
        }
    } // End while

    return -1; // Search key not found
}

// Print a header for the output
void print_header(void)
{
    puts("\nIndices:");

    // Output column head
    for (unsigned int i = 0; i < SIZE; ++i) {
        printf("%3u ", i);
    }

    puts(""); // Start new line of output

    // Output line of - characters
    for (unsigned int i = 1; i <= 4 * SIZE; ++i) {
        printf("%s", "-");
    }

    puts(""); // Start new line of output
}

// Print one row of output showing the current
// part of the array being processed
void print_row(const int b[], size_t low, size_t mid, size_t high)
{
    // Loop through entire array
    for (size_t i = 0; i < SIZE; ++i) {

        // Display spaces if outside current subarray range
        if (i < low || i > high) {
            printf("%s", "    ");
        }
        else if (i == mid) { // Display middle element
            printf("%3d*", b[i]); // Mark middle value
        }
        else { // Display other elements in subarray
            printf("%3d ", b[i]);
        }
    }

    puts(""); // Start new line of output
}