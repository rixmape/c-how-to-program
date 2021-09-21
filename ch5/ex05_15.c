// Exercise 5.15: ex05_15.c
// Calculates the hypotenuse of a right triangle given its two sides

#include <stdio.h>
#include <math.h>

// Function prototype for hypotenuse
double get_hypotenuse(double side1, double side2);

int main(void)
{
    double leg1, leg2;

    // Obtain values of two sides
    printf("%s", "Enter values of side 1 and side 2: ");
    scanf("%lf%lf", &leg1, &leg2);

    // Calculate hypotenuse
    double hypotenuse = get_hypotenuse(leg1, leg2);

    // Obtain results
    printf("Hypotenuse: %.2f", hypotenuse);
}

// Function hypotenuse
double get_hypotenuse(double side1, double side2)
{
    return sqrt(pow(side1, 2) + pow(side2, 2));
}