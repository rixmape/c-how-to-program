// Fig 7.16: fig07_16.c
// Applying sizeof to an array name returns
// the number of bytes in the array

#include <stdio.h>
#define SIZE 20

size_t get_size(float *ptr);

int main(void)
{
    float array[SIZE];

    // printf("in main: array == %p\n", array);

    printf("The number of bytes in the array is %u\n", sizeof(array));

    printf("The number of bytes returned by get_size is %u\n",
        get_size(array));

    // sizeof(array[0]) == 4, since variables of type float are stored
    // in 4 bytes of memory on this computer 
    printf("The number of elements in the array is %u\n",
        sizeof(array) / sizeof(array[0]));
}

// Return size of ptr
size_t get_size(float *ptr)
{
    // printf("in get_size: ptr == %p\n", ptr);

    // Return the size of the pointer ptr
    return sizeof(ptr);
}