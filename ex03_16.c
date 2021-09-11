// Calculates the sales tax on the total collections for a month

#include <stdio.h>

int main(void)
{
    // Initialize variables
    float county_rate = 0.05;
    float state_rate = 0.04;

    float collection, county_tax, state_tax, total_tax, sales;
    char month[30];

    // Prompt user to input values
    printf("%s", "Enter total amount collected (-1 to quit): ");

    // Begin obtaining values and calculating results
    while (scanf("%f", &collection) != EOF && collection != -1) {
        // Obtain name of month
        printf("%s", "Enter name of month: ");
        scanf("%s", month);

        // Calculate sales tax
        county_tax = collection * county_rate;
        state_tax = collection * state_rate;
        total_tax = county_tax + state_tax;
        sales = collection - total_tax;

        // Display results
        printf("\nTotal Collections: $ %.2f\n", collection);
        printf("Sales: $ %.2f\n", sales);
        printf("County Sales Tax: $ %.2f\n", county_tax);
        printf("State Salex Tax: $ %.2f\n", state_tax);
        printf("Total Sales Tax Collected: $ %.2f\n\n", total_tax);

        // Prompt user to input values
        printf("%s", "Enter total amount collected (-1 to quit): "); 
    }
}