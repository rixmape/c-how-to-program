// Fig. 7.7: fig07_07.c
// Cube a variable using pass-by-reference with a pointer argument

#include <stdio.h>

// Function cube_by_reference expects to receive an address of an
// as an integer variable as an argument.
void cube_by_reference(int *n_ptr);

int main(void)
{
    int number = 5;

    printf("The original value of number is %d", number);

    // Pass address of number to cube_by_reference
    cube_by_reference(number);
    
    printf("\nThe original value of number is %d\n", number);
}

// Calculate cube of *n_ptr; actually modifies number in main
// Function cube_by_reference takes a pointer to an int called n_ptr
void cube_by_reference(int *n_ptr)
{
    *n_ptr = *n_ptr * *n_ptr * *n_ptr; // Cube *n_ptr
}