// Fig. 7.20: fig07_20.c
// Using indexing and pointer notation with arrays

#include <stdio.h>
#define ARRAY_SIZE 4

int main(void)
{
    int b[ARRAY_SIZE] = {10, 20, 30, 40};
    int *b_ptr = b; // Create b_ptr and point it to array b

    // Output array b using array index notation
    puts("Array b printed with:\nArray index notation");

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        printf("b[%u] == %d\n", i, b[i]);
    }

    // Output array b using array name and pointer/offset notation
    puts("\nPointer/offset notation where\n"
        "The pointer is the array name");

    for (size_t offset = 0; offset < ARRAY_SIZE; ++ offset) {
        printf("*(b + %u) == %d\n", offset, *(b + offset));
    }

    // Output array b using b_ptr and array index notation
    puts("\nPointer index notation");

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        printf("b_ptr[%u] == %d\n", i, b_ptr[i]);
    }

    // Output array b using b_ptr and pointer/offset notation
    puts("\nPointer/offset notation");

    for (size_t offset = 0; offset < ARRAY_SIZE; ++offset) {
        printf("*(b_ptr + %u) == %d\n", offset, *(b_ptr + offset));
    }
}