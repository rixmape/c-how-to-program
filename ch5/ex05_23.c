// Exercise 5.23: ex05_23.c
// Calculate the amount of time in seconds between two times

#include <stdio.h>
#include <stdlib.h>

// Function prototype for get_seconds
int get_seconds(void);

int main(void)
{
    // Call get_seconds returning time1
    int time1 = get_seconds();

    // Call get_seconds returning time2
    int time2 = get_seconds();

    // Compute the difference in time
    int seconds = abs(time1 - time2);

    // Display results
    printf("Number of seconds between two times: %d", seconds);
}

// Calculate the number of seconds of a given time
int get_seconds(void)
{
    int hour, minute, second;

    // Obtain number of hours, minutes and seconds
    printf("%s", "Enter time (hours-minutes-seconds): ");
    scanf("%d-%d-%d", &hour, &minute, &second);

    return (hour * 60 * 60) + (minute * 60) + second;
}