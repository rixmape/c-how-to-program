// Exercise 6.10: ex06_10.c
// Using one-dimensional array to determine how many salespeople earned
// salaries in each of the specified ranges.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SALESPEOPLE 1000 // Total number of salesperson
#define RANGES 9 // Total number of salary ranges

// Function main begins program execution
int main(void)
{
    int gross_sales[SALESPEOPLE]; // Array to store gross sales of salespeople
    srand(time(NULL)); // Randomize the program

    // Generate gross sales for each salesperson
    for (size_t i = 0; i < SALESPEOPLE; ++i) {
        gross_sales[i] = 0 + rand() % 10001;
    }

    // Starting amount of each salary range
    int salaries[RANGES] = {200, 300, 400, 500, 600, 700, 800, 900, 1000};
    // Counter for each range
    int counters[RANGES] = {0};

    // Loop to calculate the salary of each salesperson
    for (size_t i = 0; i < SALESPEOPLE; ++i) {
        
        // Salesperson receives $200 per week plus 9% of their
        // gross sale for that week
        int salary = 200 + gross_sales[i] * 0.09;

        // Loop to increment the corresponding salary range
        for (size_t j = 0; j < RANGES; ++j) {

            // Avoid reading values outside the array of salary ranges
            if (j == (RANGES - 1)) {
                if (salaries[j] <= salary) {
                    ++counters[j];
                }
            }
            
            // Check if the salary is greater than or equal to the
            // starting amount of the current salary range, and
            // less than the starting amount of the next salary range
            else if (salaries[j] <= salary && salaries[j + 1] > salary) {
                ++counters[j];
            }
        } 
    }

    // Display results in tabular format
    printf("%-8s   %s\n", "RANGES", "COUNT");
    for (size_t i = 0; i < RANGES; ++i) {

        if (i == (RANGES - 1)) { // Print special format for last salary range
            printf(">= $%d   %d\n", salaries[i], counters[i]);
        } else {
            printf("$%d-%d   %d\n", salaries[i], salaries[i] + 99, counters[i]);
        }
    } 

}