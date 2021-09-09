// Calculates the monthly payable interest accrued on a bank customer's mortgage

#include <stdio.h>

int main(void)
{
    int account_number = 0;
    int mortgage_amount = 0;
    int mortgage_term = 0;
    float interest_rate = 0;

    float total_interest_payable = 0;
    float total_amount_payable = 0;
    int payable_interest = 0;

    while (account_number != -1) {
        // Obtain account_number
        printf("%s", "Enter account number (-1 to end): ");
        scanf("%d", &account_number);

        // Terminate program if account_number is -1
        if (account_number == -1) {
            break;
        }

        // Obtain other information
        printf("%s", "Enter mortage amount (in dollars): ");
        scanf("%d", &mortgage_amount);

        printf("%s", "Enter mortage term (in years): ");
        scanf("%d", &mortgage_term);

        printf("%s", "Enter interest rate (as a decimal): ");
        scanf("%f", &interest_rate);

        // Calculate the total payable amount
        total_interest_payable = mortgage_amount * interest_rate * mortgage_term;
        total_amount_payable = mortgage_amount + total_interest_payable;

        // Calculate the total payable interest
        // Multiply mortage term by 12 to get total number of months
        // Use integer division to round off the result to the nearest dollars
        payable_interest = total_amount_payable / (mortgage_term * 12);

        // Display the monthly payable interest
        printf("The monthly payable interest is: $ %d\n", payable_interest);
    } 
}