// A program that analyzes exam results and
// decides whether instructor should receive a bonus.

#include <stdio.h>

int main(void)
{
    int pass = 0; // counter for passing result
    int fail = 0; // counter for failed result
    int result = 0; // variable for storing result
    int counter = 0; // loop counter

    // display valid inputs
    puts("VALID USER INPUTS:\n  '1' - Pass\n  '2' - Fail\n");

    // collect and process 10 inputs
    while (counter < 10) {
        printf("%s", "Enter test result: ");
        scanf("%d", &result);

        // update number of passed and failed result
        if (result == 1) {
            pass = pass + 1;
        } else {
            fail = fail + 1;
        }

        counter = counter + 1;
    }

    // display the results
    printf("\nPassed: %d\nFailed: %d\n\n", pass, fail);

    // decide whether isntructor should receive a bonus
    if (pass > 8) {
        puts("Bonus to instructor");
    }
}