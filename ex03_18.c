// Calculates the salary of a salesperson for a week

#include <stdio.h>

int main(int argc, char *argv[])
{
    float sales = 0;
    unsigned int fixed_salary = 200;
    float commission_rate = 0.09;
    float total_commission = 0;
    float total_salary = 0;

    while (sales != -1) {
        // Obtain sales for the week
        printf("%s", "Enter sales in dollars (-1 to end): ");
        scanf("%f", &sales);

        // Terminate program if sales is -1
        if (sales == -1) {
            return 1;
        } 

        // Calculate salary for the week
        total_commission = sales * commission_rate;
        total_salary = fixed_salary + total_commission;

        // Display salary for the week
        printf("Salary is: $%.2f\n\n", total_salary);
    }

    return 0;
}