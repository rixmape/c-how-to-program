// Exercise 6.19: ex06_19.c
// Simulates rolling of two dice

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DICE 6 // Number of dice to be rolled
#define SUM_SIZE (6 * DICE) + 1 // Number of possible sums of the rolled dice
#define ROLL 36000 // Number of rolls

int main(void)
{
    // Initialize the array to contain the frequency of sums
    int freq[SUM_SIZE] = {0};

    srand(time(NULL)); // Randomize the program

    // Roll the dice ROLL times
    for (int i = 0; i < ROLL; ++i) {

        // Roll a die DICE times and get the sum
        int sum = 0;
        for (int j = 0; j < DICE; ++j) {
            sum += 1 + rand() % 6; // Roll a six-sided die
        }

        // Increment the element of array freq equal to the sum of the dice
        ++freq[sum];
    }

    // Print the results in tabular format
    printf("%4s%12s\n", "SUM", "FREQUENCY");
    for (int val = DICE; val < SUM_SIZE; ++val) {
        printf("%4d%12d\n", val, freq[val]);
    }
    
}