// Exercise 5.9: ex05_09.c
// Calculates car rental charges of three customers

#include <stdio.h>

double calculate_charges(int hour);

int main(void)
{
    int hour1, hour2, hour3, total_hour;

    double charge1, charge2, charge3, total_charge;

    // Obtain rent hours and calculate the charge for first customer
    printf("%s", "Enter rent hours for first customer: ");
    scanf("%d", &hour1);
    charge1 = calculate_charges(hour1);

    // Obtain rent hours and calculate the charge for second customer
    printf("%s", "Enter rent hours for second customer: ");
    scanf("%d", &hour2);
    charge2 = calculate_charges(hour2);

    // Obtain rent hours and calculate the charge for third customer
    printf("%s", "Enter rent hours for third customer: ");
    scanf("%d", &hour3);
    charge3 = calculate_charges(hour3);

    // Calculate total hours and charges
    total_hour = hour1 + hour2 + hour3;
    total_charge = charge1 + charge2 + charge3;

    // Display results
    printf("\n%-7s%6s%10s\n", "Car", "Hours", "Charge");
    printf("%-7d%4d%12.2f\n", 1, hour1, charge1);
    printf("%-7d%4d%12.2f\n", 2, hour2, charge2);
    printf("%-7d%4d%12.2f\n", 3, hour3, charge3);
    printf("%-7s%4d%12.2f\n", "TOTAL", total_hour, total_charge);
}

double calculate_charges(int hour)
{
    double rent_fee, charge;

    if (24 < hour) {

        double max_daily_fee = calculate_charges(24);
        return max_daily_fee + calculate_charges(hour - 24);

    } else {

        if (8 >= hour) { // Cars rented for less than or equal to 8 hours
            // Implement a minimum fee of 25 dollars
            rent_fee = 25;        
        } else { // Cars rented for more than 8 hours
            // Implement of additional fee of 5 dollars per hour
            rent_fee = 25 + ((hour - 8) * 5);
        }

        // Set a maximum daily rent fee of 50
        if (50 < rent_fee) {
            rent_fee = 50;
        }

        // Calculate daily charge with service tax
        charge = rent_fee + (hour * 0.5);

        // Return daily charge 
        return charge;
    }
}
