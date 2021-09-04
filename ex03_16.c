// Calculates the sales tax on the total collections for a month

#include <stdio.h>

int main(void)
{
    // Initialize variables
    float county_rate = 0.05;
    float state_rate = 0.04;

    float total_collection = 0;
    char month[30];
    float county_tax = 0;
    float state_tax = 0;
    float total_tax = 0;
    float sales = 0;

    // Begin obtaining values and calculating results
    while (total_collection != -1) {
        // Obtain total collection
        printf("%s", "Enter total amount collected (-1 to quit): "); 
        scanf("%f", &total_collection);

        // Terminate program if input is -1
        if (total_collection == -1) {
            break;
        }

        // Obtain name of month
        printf("%s", "Enter name of month: ");
        scanf("%s", month);

        // Calculate sales tax
        county_tax = total_collection * county_rate;
        state_tax = total_collection * state_rate;
        total_tax = county_tax + state_tax;
        sales = total_collection - total_tax;

        // Display results
        printf("Total Collections: $ %.2f\n", total_collection);
        printf("Sales: $ %.2f\n", sales);
        printf("County Sales Tax: $ %.2f\n", county_tax);
        printf("State Salex Tax: $ %.2f\n", state_tax);
        printf("Total Sales Tax Collected: $ %.2f\n\n", total_tax);
    }
}