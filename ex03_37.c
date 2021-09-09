// Calculates person's age, maximum heart rate and target-heart-rate range

#include <stdio.h>

int main(void)
{
    int currrent_month, currrent_day, currrent_year;
    int bdate_month, bdate_day, bdate_year;
    int age, max_hrate, min_target_hrate, max_target_hrate;

    printf("%s", "Enter current date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &currrent_month, &currrent_day, &currrent_year);

    // printf("Current date: %d/%d/%d",
    //         currrent_month, currrent_day, currrent_year);

    printf("%s", "Enter your birthdate (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &bdate_month, &bdate_day, &bdate_year);

    // Calculate age
    age = currrent_year - bdate_year;

    // Calculate maximum heart rate
    max_hrate = 220 - age;

    // Calculate minimum of target-heart-rate range
    min_target_hrate = max_hrate * 0.5;

    // Calculate maximum of target-heart-rate range
    max_target_hrate = max_hrate * 0.85;

    // Display results
    printf("Age: %d\n", age);
    printf("Maximum heart rate: %d beats/minute\n", max_hrate);
    printf("Target-heart-rate range: %d-%d beats/minute",
            min_target_hrate, max_target_hrate);
}