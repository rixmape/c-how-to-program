// Fig. 7.15: fig07_15.c
// Putting values into an array, sorting values into
// an ascending order and printing the result of the array.

#include <stdio.h>
#define SIZE 10

void bubble_sort(int * const array, const size_t size);

int main(void)
{
    // Initialize array a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // Loop through array a
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    bubble_sort(a, SIZE);

    puts("\nData items in ascending order");

    // Loop through array a
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    puts("");
}

// Sort an array of integers using bubble sort algorithm
void bubble_sort(int * const array, const size_t size)
{
    void swap(int *element1_ptr, int *element2_ptr);

    // Loop to control passes
    for (unsigned int pass = 0; pass < size - 1; ++pass) {

        // Loop to control comparison for each pass
        for (size_t j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// Swap values at memory locations to which
// element1_ptr and element2_ptr point
void swap(int *element1_ptr, int *element2_ptr)
{
    int hold = *element1_ptr;
    *element1_ptr = *element2_ptr;
    *element2_ptr = hold;
}