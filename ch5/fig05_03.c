// Fig. 5.3: fig05_03.c
// Creating and using a programmer-defined function.

#include <stdio.h>

int square(int y); // function prototype

int main(void)  // main does not receive any values
{
    // loop 10 times and calculate and output square of x each time
    for (int x = 1; x <= 10; ++x) {
        printf("%d ", square(x)); // function call
    }

    puts("");
}

// square function definition returns the square of its parameter
int square (int y) { // y is a copy of the argument of the function
    return y * y; // return the square of y as an int
}