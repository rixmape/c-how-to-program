// Fig. 2.5: fig02_05.c
// Addition program
#include <stdio.h>

// function main begins program execution
int main(void)
{
    int integer1; // first integer to be entered by user
    int integer2; // second integer to be entered by used

    printf("Enter first integer\n"); // prompt
    scanf("%d", &integer1); // read an integer

    printf("Enter second integer\n"); // prompt
    scanf("%d", &integer2); // read an integer

    int sum; // variable in which sum will be stored
    sum = integer1 + integer2; // assign total to sum
    
    printf("Sum is %d\n", sum); // print sum
} // end function main