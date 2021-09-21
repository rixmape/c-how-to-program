// Exercise 5.10: ex05_10.c
// Rounding numbers to the nearest integer using function ceil

#include <stdio.h>
#include <math.h>

int main(void)
{
    int num;
    
    // Obtain initial user input to begin loop
    printf("%s", "Enter number (-1 to end): ");

    // End loop if there is an input and the input is not -1
    while((scanf("%d", &num) == 1) && (num != -1)) {
        
        // Round the number to the nearest integer not less than the number
        double y = ceil(num + 0.5);
        printf("ceil(%d + 0.5) is %.2f\n", num, y);

        // Obtain user input
        printf("%s", "Enter number (-1 to end): ");
    }
}