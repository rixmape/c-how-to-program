// Fig. 4.2: fig04_02.c
// Counter-controlled iteration with the for statement.

#include <stdio.h>

int main(void)
{
    // Initialization, iteration, and increment
    // are all included in the for statement header.
    for (unsigned int counter = 1; counter <= 10; ++counter) {
        printf("%d\n", counter);
    }
}