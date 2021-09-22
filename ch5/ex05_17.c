// Exercise 5.17: ex05_17.c
// Determine a right-angled triangle from three given sides

#include <stdio.h>
#include <math.h>

int is_valid_triangle(double side1, double side2, double side3);
int is_right_triangle(double side1, double side2, double side3);

int main(void)
{
    double x, y, z;
    // Obtain three side lengths
    printf("%s", "Enter lengths of three sides: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    // Check if the sides are valid
    if (is_valid_triangle(x, y, z)) {
        // Check if the sides form a right triangle
        if (is_right_triangle(x, y, z)) {
        puts("Sides resemble a right-angled triangle.");
        } else {
            puts("Sides do not resemble a right-angled triangle.");
        }
    } else {
        puts("Sides do not form any kind of triangle.");
    }
    
}

// Check if the three sides form a valid triangle
int is_valid_triangle(double side1, double side2, double side3)
{
    // Use Triangle Inequality Theorem to test if a tringle is formed
    return side1 + side2 > side3 &&
        side1 + side3 > side2 &&
        side2 + side3 > side1;
}

// Check if right-angled triangle is formed
int is_right_triangle(double side1, double side2, double side3)
{
    // Use Pythagorean Theorem to test if right triangle exists
    // Test for every possible value of hypotenuse
    return side1 * side1 == side2 * side2 + side3 * side3 ||
        side2 * side2 == side2 * side2 + side1 * side1 ||
        side3 * side3 == side2 * side2 + side1 * side1;
}