// Fig. 4.7: fig04_07.c
// Counting letter grades with switch.

#include <stdio.h>

int main(void)
{
    // initialize counters for letter grades
    unsigned int aCount = 0;
    unsigned int bCount = 0;
    unsigned int cCount = 0;
    unsigned int dCount = 0;
    unsigned int fCount = 0;

    puts("Enter letter grades.");
    puts("Enter the EOF character to end input.");
    int grade; // one grade

    // loop until user types end-of-file key sequence
    while ((grade = getchar()) != EOF) {

        // determine which grade is input
        switch (grade) {

            // count letter grade A or a
            case 'A':
            case 'a':
                ++aCount;
                break;

            // count letter grade B or b
            case 'B':
            case 'b':
                ++bCount;
                break;

            // count letter grade C or c
            case 'C':
            case 'c':
                ++cCount;
                break;

            // count letter grade D or d
            case 'D':
            case 'd':
                ++dCount;
                break;

            // count letter grade F or f
            case 'F':
            case 'f':
                ++fCount;
                break;

            // ignore newlines, tabs and spaces in input
            case '\n':
            case '\t':
            case ' ':
                break;

            // catch all other characters
            default:
                puts("Incorrect letter grade entered.");
                puts("Enter a new grade.");
                break; 
        }
    }

    // output summary of results
    puts("\nTotals for each letter grade are:");
    printf("A: %u\n", aCount);
    printf("B: %u\n", bCount);
    printf("C: %u\n", cCount);
    printf("D: %u\n", dCount);
    printf("F: %u\n", fCount);
}