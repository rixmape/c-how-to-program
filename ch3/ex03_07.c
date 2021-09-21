// Calculates x raised to the y power

#include <stdio.h>

int main(void)
{
    unsigned int x, y, product, i = 1;

    printf("%s", "Enter the value of x: ");
    scanf("%u", &x);

    printf("%s", "Enter the value of y: ");
    scanf("%u", &y);

    product = x;
    while (i < y) {
        product = product * x;
        i++;
    }

    printf("\n%u raised to %u power is %u", x, y, product);
}