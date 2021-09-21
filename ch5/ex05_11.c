// Exercise 5.11: ex05_11.c
// Rounding numbers to the nearest integer using function floor

#include <stdio.h>
#include <math.h>

double round_to_integer(double number);
double round_to_tenths(double number);
double round_to_hundredths(double number);
double round_to_thousandths(double number);

int main(void)
{
    double num;

    // Obtain number
    printf("%s", "Enter number: ");
    scanf("%lf", &num);

    // Round the number to the nearest integer
    printf("Rounded to the nearest integer: %.5f\n", round_to_integer(num));

    // Round the number to the tenths position
    printf("Rounded to the tenths position; %.5f\n", round_to_tenths(num));

    // Round the number to the hundredths position
    printf("Rounded to the hundredths position; %.5f\n",
        round_to_hundredths(num));

    // Round the number to the thousandths position 
    printf("Rounded to the thousandths position; %.5f\n",
        round_to_thousandths(num));
}

double round_to_integer(double number)
{
    return floor(number + .5);
}

double round_to_tenths(double number)
{
    return floor(number * 10 + .5) / 10;
}

double round_to_hundredths(double number)
{
    return floor(number * 100 + .5) / 100;
}

double round_to_thousandths(double number)
{
    return floor(number * 1000 + .5) / 1000;
}