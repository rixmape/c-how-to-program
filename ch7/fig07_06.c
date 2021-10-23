// Fig. 7.6: fig07_06.c
// Cube a variable using pass-by-value

#include <stdio.h>

int cube_by_value(int n);

int main(void)
{
    int number = 5; // Initialize number

    printf("The original value of number is %d", number);

    // Pass number by value to cube_by_value
    number = cube_by_value(number);

    printf("\nThe new value of number is %d\n", number);
}

// Calculate and return cube of integer argument
int cube_by_value(int n)
{
    return n * n * n; // Cube local variable n and return result
}