// Exercise 5.43: ex05_43.c
// What does the following program do?

#include <stdio.h>

unsigned int mystery(unsigned int a, unsigned int b);

int main(void)
{
    printf("%s", "Enter two positive integers: ");
    unsigned int x, y;
    scanf("%u%u", &x, &y);

    printf("The result is %u\n", mystery(x, y));
}

// Paramater b must be a positive integer
// to prevent infinite recursion
unsigned int mystery(unsigned int a, unsigned int b)
{
    // Base case
    if (1 == b) {
        return a;
    } else { // Recursive step
        return a + mystery(a, b - 1);
    }
}