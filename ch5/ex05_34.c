// Exercise 5.34: ex05_34.c
// Recursive exponentiation

#include <stdio.h>

double power(double base, double exponent); // Function prototype

int main(void)
{
    double base, exponent;
    // Obtain base and exponent
    printf("%s", "Enter base and exponent: ");
    scanf("%lf%lf", &base, &exponent);

    printf("%.2f", power(base, exponent));
}

// Calculate power using recursion
double power(double base, double exponent)
{
    if (exponent == 1) {
        return base;
    } else {
        return base * power(base, exponent - 1);
    }
}