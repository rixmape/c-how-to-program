// Figure 7.26: fig07_26.c
// Multipurpose sorting program using function pointers.

#include <stdio.h>
#define SIZE 10

void bubble(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void)
{
    // Initialize unordered array a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    printf("%s", "Enter 1 to sort in ascending order,\n"
        "Enter 2 to sort in descending order: ");

    int order;
    scanf("%d", &order);

    puts("\nData items in original order");
    for (size_t counter = 0; counter < SIZE; ++counter) {
        printf("%5d", a[counter]);
    }

    // Sort array in ascending order; pass function ascending
    // as an argument to specify ascending sorting order
    if (1 == order) {
        bubble(a, SIZE, ascending);
        puts("\nData items in ascending order");
    }
    else { // Pass function descending
        bubble(a, SIZE, descending);
        puts("\nData items in descending order");
    }

    // Output sorted order
    for (size_t counter = 0; counter < SIZE; ++counter) {
        printf("%5d", a[counter]);
    }

    puts("\n");
}

// Multipurpose bubble sort; parameter compare is a pointer
// to the comparison function that determines the sorting order
void bubble(int work[], size_t size, int (*compare)(int a, int b))
{
    void swap(int *element1_ptr, int *element2_ptr);

    // Loop to control passes
    for (unsigned int pass = 1; pass < size; ++pass) {

        // Loop to control the number of comparison per pass
        for (size_t count = 0; count < size - 1; ++count) {

            // If adjacent elements are out of order, swap them
            if((*compare)(work[count], work[count + 1])) {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

// Swap values at memory locations to which element1_ptr and
// element2_ptr point
void swap(int *element1_ptr, int *element2_ptr)
{
    int hold = *element1_ptr;
    *element1_ptr = *element2_ptr;
    *element2_ptr = hold;
}

// Determine whether elements are out of order for an ascending
// order sort
int ascending(int a, int b)
{
    return b < a; // Should swap is b is less than a
}

// Determine whether elements are out of order for a descending
// order sort
int descending(int a, int b)
{
    return b > a; // Should swap if b is greater than a
}