// Performs different arithmetic operations on two numbers.

#include <stdio.h>

int main(void)
{
    int x, y;

    printf("%s", "Enter first number: ");
    scanf("%d", &x);

    printf("%s", "Enter second number: ");
    scanf("%d", &y);

    // Calculate sum
    printf("Sum: %d\n", x + y);

    // Calculate difference
    printf("Difference: %d\n", x - y);

    // Calculate product
    printf("Product: %d\n", x * y);

    // Calculate quotient
    printf("Quotient: %d\n", x / y);

    // Calculate remainder
    printf("Remainder: %d\n", x % y);
}