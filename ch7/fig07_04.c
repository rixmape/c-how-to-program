// Fig. 7.4: fig07_04.c
// Using the & and * pointer operators

#include <stdio.h>

int main(void)
{
    int a = 7;
    int *a_ptr = &a; // Set a_ptr to the address of a

    printf("The address of a is %p"
            "\nThe value of a_ptr is %p", &a, a_ptr);

    printf("\n\nThe value of a is %d"
            "\nThe value of *a_ptr is %d", a, *a_ptr);

    printf("\n\nShowing that * and & are complements of "
            "each other\n&*a_ptr = %p"
            "\n*&a_ptr = %p\n", &*a_ptr, *&a_ptr);
}