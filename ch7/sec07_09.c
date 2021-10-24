// Section 7.9: sec07_09.c
// Relationship between pointers and arrays

#include <stdio.h>

int main(void)
{
    int array[5] = {10, 11, 12, 13, 14};
    int *ptr_array = array;

    printf("array == %p\n", array);
    printf("ptr_array == %p\n", ptr_array);
    printf("array == ptr_array is %s\n\n",
        array == ptr_array ? "True" : "False");

    // Referencing using pointer/offset notation with a pointer
    printf("&array[1] == %p\n", &array[1]);
    printf("(ptr_array + 1) == %p\n", ptr_array + 1);
    printf("&array[1] == (ptr_array + 1) is %s\n\n",
        &array[1] == ptr_array + 1 ? "True" : "False");

    // Referencing using pointer/offset notation with an array name
    printf("&array[1] == %p\n", &array[1]);
    printf("(array + 1) == %p\n", array + 1);
    printf("&array[1] == (array + 1) is %s\n\n",
        &array[1] == array + 1 ? "True" : "False");

    // Dereferencing using array indexing and
    // pointer/offset notation with a pointer
    printf("array[1] == %d\n", array[1]);
    printf("*(ptr_array + 1) == %d\n", *(ptr_array + 1));
    printf("array[1] == *(ptr_array + 1) is %s\n\n",
        array[1] == *(ptr_array + 1) ? "True" : "False");

    // Dereferencing using pointer/index notation
    puts("A pointer can be indexed as in:");
    printf("ptr_array[1] == %d", ptr_array[1]);
}