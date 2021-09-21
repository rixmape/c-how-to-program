// Exercise 5.16: ex05_16.c
// Calculate the area of a triangle given its three sides

#include <stdio.h>
#include <math.h>

// Function prototype for get_area
int check_sides(double side1, double side2, double side3);
double get_area(double side1, double side2, double side3);

int main(void)
{
    double x, y, z;
    // Obtain values for three sides
    printf("%s", "Enter value of three sides: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    // Calculate the area of the triangle if the given sides are valid
    if (check_sides(x, y, z)) {
        double area = get_area(x, y, z);
        printf("Area: %.2f", area);
    } else {
        puts("The given sides do not resemble a triangle.");
    }
}

// Check if the given three sides are valid
int check_sides(double side1, double side2, double side3)
{
    // If all the possible combinations of the two side lengths
    // are greater than the third side, then a triangle exists
    if (side1 + side2 < side3) {
        return 0;
    } else if (side1 + side3 < side2) {
        return 0;
    } else if (side2 + side3 < side1) {
        return 0;
    } else {
        return 1;
    }
}

// Calculate the area of a triangle
double get_area(double side1, double side2, double side3)
{
    // Compute the semiperimeter
    double semip = (side1 + side2 + side3) / 2;
    // Compute the area
    return sqrt(semip * (semip - side1) * (semip - side2) * (semip - side3));
}