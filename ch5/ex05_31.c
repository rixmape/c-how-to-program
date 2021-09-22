// Exercise 5.21: ex05_31.c
// Simulates coin tossing

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip(void); // Function prototype for function flip

int main(void)
{
    int toss_count = 100;
    int heads = 0;
    int tails = 0;

    // Send random number generator with current time
    srand(time(NULL));

    for (int i = 1; i <= toss_count; ++i) {
        if (flip()) {
            puts("Heads");
            ++heads;
        } else {
            puts("Tails");
            ++tails;
        }
    }

    // Display statistics
    printf("\nHeads: %d\nTails: %d", heads, tails);
}

// Flip a coin and return 1 for heads and 0 for tails
int flip(void)
{
    // Seed rand with current time
    int face = 0 + rand() % 2;
    printf("%d ", face);
    return face;
} 