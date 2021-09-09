// Projects the estimated world population after 1, 2, 3, 4, and 5 years

#include <stdio.h>

int main(void)
{
    long long int pop_total = 7874965732;
    float growth_rate = 0.0101;
    unsigned int pop_increase = 0;
    unsigned int year = 1;

    // Estimate world population every year within 5 years
    while (year <= 5) {
        // Calculate number of individuals added after a year
        pop_increase = pop_total * growth_rate;

        // Calculate new population size
        pop_total = pop_total + pop_increase;

        // Display world population
        printf("Estimated population after %d years: %llu\n", year, pop_total);

        // Increment year
        ++year;
    }
}