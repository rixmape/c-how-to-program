// Performs different arithmetic operations in C

#include <stdio.h>

int main(void)
{
    int x = 8 + 15 * (6 - 2) - 1;
    printf("x = %d\n", x);

    int y = 5 % 5 + 5 * 5 - 5 / 5;
    printf("y = %d\n", y);

    int z = (5 * 7 * (5 + (7 * 5 / (7))));
    printf("z = %d\n", z);
}