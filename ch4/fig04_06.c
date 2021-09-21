// Fig. 4.6: fig04_06.c
// Calculating compound interest.

#include <stdio.h>
#include <math.h>

int main(void)
{
    double principal = 1000; // starting principal
    double rate = 0.05; // annual interest rate

    // output table column heads
    printf("%4s%21s\n", "Year", "Amount on deposit");

    // calculate amount of deposit for each of ten years
    for (unsigned int year = 1; year <= 10; ++year) {
        
        // calculate new amount for specified year
        double amount = principal * pow(rate + 1.0, year);

        // output one table row
        printf("%4u%21.2f\n", year, amount);
    }
}