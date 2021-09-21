// Fig. 3.8: fig03_08.c
// Class-average program with sentinel-controlled iteration
#include <stdio.h>

// function main begins program execution
int main(void)
{
    unsigned int counter; // number of grades entered
    int grade; // grade value
    int total; // sum of grades

    float average; // number with decimal point for average

    // initialization phase
    total = 0;
    counter = 0;

    // processing phase
    // get first grade from user
    printf("%s", "Enter grade, -1 to end: ");
    scanf("%d", &grade);

    // loop while sentinel value not yet read from user
    while (grade != -1) {
        total = total + grade;
        counter = counter + 1;

        printf("%s", "Enter grade, -1 to end: ");
        scanf("%d", &grade);
    }

    // termination phase
    // if user entered at least one grade
    if (counter != 0) {
        // calculate average of all grades entered
        average = (float) total / counter; // avoid truncation

        // display average with two digits of precision
        printf("Class average is %.2f\n", average);
    } else {
        puts("No grades were entered!");
    }
}